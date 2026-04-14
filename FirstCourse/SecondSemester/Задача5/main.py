def main():
    with open('input.txt', 'r') as file:
        line = file.readline()
        numbers = list(map(int, line.split()))

    print(func(numbers))

def func(arr):
    if not arr:
        return 0

    count = 1
    for i in range(1, len(arr)):
        if arr[i] <= arr[i-1]:
            count += 1
    return count

main()
