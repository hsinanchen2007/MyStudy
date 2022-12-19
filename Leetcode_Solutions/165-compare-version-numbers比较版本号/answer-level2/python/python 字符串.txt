### 解题思路
此处撰写解题思路
注意1.0与1.001比较时候要补0

### 代码

```python3
class Solution:
    def compareVersion(self, s1: str, s2: str) -> int:
        i,j = 0,0

        while i<len(s1) or j<len(s2):
            k1 = i
            while k1<len(s1) and s1[k1]!='.':
                k1+=1
            k2 = j
            while k2<len(s2) and s2[k2]!='.':
                k2+=1
            if i==k1:
                a=0
            else:
                a = int(s1[i:k1])
            if j==k2:
                b =0
            else:
                b = int(s2[j:k2])
            if a>b:
                return 1
            if a<b:
                return -1
            i = k1+1

            j = k2+1
        return 0       
```