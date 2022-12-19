### 解题思路
此处撰写解题思路
![2808bad3d3675dfa374e1019d1e7861.png](https://pic.leetcode-cn.com/240a3d569ecf41f39534af21862fd3faf8ef233c2662bd40b2a1b44194dbd902-2808bad3d3675dfa374e1019d1e7861.png)
主要考虑头部、中间、尾部的情况
### 代码

```python3
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        num=[]
        for i in range(len(S)):
            if S[i]==C:
                num.append(i)#索引
        lists=[]
        j=0
        i=0
        while i<len(S):
            if j==0 and i<num[j]:#头部
                lists.append(num[j]-i)
                i+=1
            elif i==num[j]:
                lists.append(0)
                if j<len(num)-1:
                    j+=1
                i+=1
            elif i<=num[j] and i>num[j-1]:#中间
                lists.append(min(num[j]-i,i-num[j-1]))
                i+=1
            elif j==len(num)-1 and i>num[j]:#尾部
                lists.append(i-num[j])
                i+=1       
        return lists
```