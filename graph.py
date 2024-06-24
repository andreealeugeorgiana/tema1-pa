import numpy as np
import matplotlib.pyplot as plt

def plot_absolute_function(a_values, b_values, x_range=(-100, 100), num_points=10000):
    x = np.linspace(x_range[0], x_range[1], num_points)
    for a, b in zip(a_values, b_values):
        y = a - np.abs(x - b)
        plt.plot(x, y, label=f"a={a}, b={b}")
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of f(x) = a - |x - b|')
    plt.legend()
    plt.grid(True)
    plt.show()

# Example usage
a_values = [39, 24, 24, 50, 44, 41, 34, 15, 19, 44, 55, 57, 20, 27, 40, 54, 56, 41, 58, 22, 48, 57, 19, 55, 43, 38, 44, 47, 45, 41, 21, 55, 52, 17, 32, 23, 27, 47, 38, 31, 19, 24, 44, 50, 28, 30, 36, 30, 45, 48]
b_values = [30, 15, 27, 50, 23, 17, 37, 25, 22, 55, 54, 29, 50, 29, 16, 46, 55, 11, 11, 25, 50, 50, 25, 42, 41, 32, 36, 47, 54, 36, 45, 57, 43, 43, 23, 22, 21, 41, 47, 50, 43, 41, 43, 43, 32, 52, 32, 47, 13, 25]
plot_absolute_function(a_values, b_values)