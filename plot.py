import matplotlib.pyplot as plt

# Define the points
points = [
    (15,4), (21,6), (35,12), (39,12), (51,8), (55,20), (85,8), (91,12), (95,36), (133,18),
    (143,60), (187,40), (221,24), (69,22), (87,28), (93,10), (111,36), (123,20), (129,14),
    (141,46), (159,52), (183,60), (219,18), (267,22), (291,48), (115,44), (155,20), (215,28),
    (235,92), (295,116)
]

# Extract x and y coordinates
x_coords = [point[0] for point in points]
y_coords = [point[1] for point in points]

# Plot the points
plt.scatter(x_coords, y_coords)
plt.title('Scatter Plot of Points')
plt.xlabel('X')
plt.ylabel('Y')
plt.grid(True)
plt.show()
