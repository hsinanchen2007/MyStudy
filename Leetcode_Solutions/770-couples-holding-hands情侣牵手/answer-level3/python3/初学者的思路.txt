### 解题思路
1、假设整数对（A,B）表示一对情侣，从第一个数开始配对：idx表示A下标，第一对情侣的A下标为0
2、A的位置保持不变，查找并调整B的位置来实现配对
    如果A是偶数：则B是A+1
    如果B是奇数：则B是A-1
3、以当前A的下一个数字为起始，搜索整个list，找到符合条件的B
    如果B正好在A的后一位：查找下一对情侣
    如果B不在A的后一位：交换B和A后面一个数交换，查找下一对情侣
4、查找下一对（A1，B1）：A1的位置为idx+2，B1从list的idx+3开始查找
5、一直把list查完为止

### 代码

```python3
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        n = len(row)
        count = 0
        cur = 0
        i = 0
        while i < n and cur+1 < n:
            print(row[i])
            if row[cur] % 2 == 0:
                if row[i] == row[cur]+1:
                    if i != cur+1:
                        print(row[i], i)
                        tmp = row[i]
                        row[i] = row[cur+1]
                        row[cur+1] = tmp
                        count += 1
                        print(row)
                    cur = cur+2
                    i = cur+1
                    continue
                else:
                    i += 1
            else:
                if row[i] == row[cur]-1:
                    if i != cur+1:
                        print(row[i], i)
                        tmp = row[i]
                        row[i] = row[cur+1]
                        row[cur+1] = tmp
                        count += 1
                        print(row)
                    cur = cur+2
                    i = cur+1
                    continue
                else:
                    i += 1
        return count
            
```