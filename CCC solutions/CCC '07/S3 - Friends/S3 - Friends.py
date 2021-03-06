import sys

sys.setrecursionlimit(20000)


def dfs(start, end, current, dis, visited):
    visited[current] = True
    if current == end:
        return dis
    neighbors = dict.get(current)
    for i in neighbors:
        if i not in visited.keys():
            dis += 1
            dis = dfs(start, end, i, dis, visited)
        else:
            return None
    return dis


def main():
    for i in check:
        dis = -1
        visited = {}
        dis = dfs(i[0], i[1], i[0], dis, visited)
        if dis is None:
            print("No")
        else:
            print("Yes {}".format(dis))


n = int(input())
dict = {}
check = []
for _ in range(n):
    a = list(map(int, input().split()))
    dict[a[0]] = [a[1]]

while 1:
    a = list(map(int, input().split()))
    if a[0] == 0 == a[1]:
        break
    check.append(a)

main()