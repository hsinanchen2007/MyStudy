### 解题思路

很容易想到是:

f(i,j)=min(f(i-1,j-1),f(i-1,j)+1,f(i,j-1)+1) if word1[i]!=word[j]
f(i,j)=min(f(i-1,j-1)+1,f(i-1,j)+1,f(i,j-1)+1) if word1[i]==word[j]

直接写递归一定超时。。

考虑自下而上，肯定可以用O(MN)空间搞定
但每一刻状态只和i-1,j-1有关，可以少一个状态，于是如下。


### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        length1=len(word1)
        length2=len(word2)
        if length1==0:
           return length2
        temp1=[length1+length2 for i in range(length2+1)]
        #temp1装上一刻。
        temp2=[length2+length1 for i in range(length2+1)]
        #temp2装这一刻。
        for i in range(-1,length1):
            for j in range(-1,length2):#-1...length2-1
                if i==-1:
                   temp2[j+1]= j+1
                elif j==-1:
                   temp2[j+1]= i+1
                elif word1[i]==word2[j]:
                   temp2[j+1]=min(temp1[j],temp1[j+1]+1,temp2[j]+1)
                elif word1[i]!=word2[j]:
                   temp2[j+1]=min(temp1[j]+1,temp1[j+1]+1,temp2[j]+1)
            
            temp1,temp2=temp2,temp1 
            
              
        return  temp1[-1]
```