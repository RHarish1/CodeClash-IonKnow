def count_holes_and_sizes(board):
    # Keeps track of which white cells have already been visited
    visited = [[False] * 10 for _ in range(10)]
    holes = []

    def dfs(i, j):
        # Use DFS to explore all white cells connected to (i, j)
        stack = [(i, j)]
        size = 0

        while stack:
            x, y = stack.pop()
            if visited[x][y]:
                continue

            visited[x][y] = True
            size += 1

            # Check all 4 directions (no diagonals)
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = x + dx, y + dy

                if 0 <= nx < 10 and 0 <= ny < 10:
                    # If neighbor is white and unvisited, add it to stack
                    if board[nx][ny] == 0 and not visited[nx][ny]:
                        stack.append((nx, ny))

        return size

    # Iterate through every cell in the board
    for i in range(10):
        for j in range(10):
            # If it's a white cell and we haven't visited it yet, it's a new region
            if board[i][j] == 0 and not visited[i][j]:
                region_size = dfs(i, j)
                holes.append(region_size)

    return holes
if __name__ == "__main__":
    # Read the board from input
    print("Enter the 10 rows of the checkerboard (each row with 10 digits of 0 or 1):")
    board = []

    for _ in range(10):
        row = input().strip()
        # Convert each character in the row to an integer and store it
        board.append([int(ch) for ch in row])

    # Get all hole sizes
    holes = count_holes_and_sizes(board)
    holes.sort()  # Not needed, but for consistent output

    # Print results
    print(f"{len(holes)} holes found.")
    print("Sizes:", *holes)

# Input given in the problem statement
board = [
    [1, 0, 1, 1, 1, 1, 1, 0, 1, 1],
    [1, 1, 1, 0, 0, 1, 0, 0, 1, 1],
    [0, 1, 0, 0, 1, 1, 0, 0, 0, 0],
    [0, 1, 1, 0, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 0, 1, 1, 1, 0, 0, 0],
    [1, 0, 1, 1, 1, 0, 1, 0, 0, 0],
    [1, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    [1, 1, 1, 1, 1, 1, 1, 0, 0, 0],
    [0, 0, 0, 1, 0, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
]

holes = count_holes_and_sizes(board)
holes.sort()

print(f"{len(holes)} holes found.")
print("Sizes:", *holes)
