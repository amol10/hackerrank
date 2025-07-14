n, k = input().split()

s = input().split()
print(s)
print(k)

p = []

def swap(s, i1, i2):
    e1 = s[i1]
    s[i1] = s[i2]
    s[i2] = e1

def permutations(s, idx):
    if (idx == len(s)):
        p.add(s)
        return

    for i in range(idx, len(s)):
        swap(s, idx, i)
        permutations(s, idx + 1)
        swap(s, idx, i)

print(p)

