### 解题思路
根据官方的解题思路进行分情况讨论。

### 代码

```python3
class Solution:
    def buddyStrings(self, A: str, B: str):
        if len(A) != len(B): #长度不相等则False
            return False
        else:
            if A == B: #如果长度相等，且内容一样
                for i in range(len(A)):
                    for j in range(i+1,len(B)):
                        if A[i] == B[j]: #是否在不同的位置上有相同的字母用以交换
                            return True 
                else:
                    return False
            else:  #如果长度相等，且内容不一样
                index = []
                a = 0
                for i in range(len(A)):
                    if A[i] == B[i]:
                        pass
                    else:
                        index.append(i) #比对出不一样内容的全部位置
                        a += 1
                if len(index) != 2: #如果不一样的地方不为2处，False
                    return False
                else: #不同处交换后比对是否一致
                    C = list(A) 
                    C[index[0]] = A[index[1]]
                    C[index[1]] = A[index[0]]
                    rst = "".join(C)
                    if rst == B:
                        return True
        return False


```