


```
# 四周都填充-1
M.insert(len(M), [-1]*len(M[0]))
M.insert(0, [-1]*len(M[0]))
for i in range(len(M)):
    M[i].insert(len(M[0]), -1)
    M[i].insert(0, -1)

row, col = len(M), len(M[0])
N = [[0 for i in range(col-2)] for j in range(row-2)]

for i in range(1, row-1):
    for j in range(1, col-1):
        temp = [M[i-1][j-1], M[i-1][j], M[i-1][j+1], M[i][j-1], M[i][j], M[i][j+1], M[i+1][j-1], M[i+1][j], M[i+1][j+1]]
        temp2 = [x for x in temp if x != -1]
        N[i-1][j-1] = sum(temp2) // len(temp2)
        
return N
```

