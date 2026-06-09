### 解题思路
O(n)解法：大概思路就是找到每个最小abc子字符串，从左往右找，同时，最小字符串左右可无限延长，均符合要求，但是需要在最后的计算时考虑重复字符串，把这个想清楚就完事了。

### 代码

```python3
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n=len(s)
        re=0
        count=0
        temp=[-1,-1,-1]
        re=[]
        for i in range(len(s)):
            if s[i]=='a':
                if temp[0]==-1:
                    count+=1
                temp[0]=i
            elif s[i]=='b':
                if temp[1]==-1:
                    count+=1
                temp[1]=i
            else:
                if temp[2]==-1:
                    count+=1
                temp[2]=i
            if count==3:
                re.append((min(temp),i))
                temp[temp.index(min(temp))]=-1
                count-=1
        if not len(re):
            return 0
        return_=0
        last=-1
        for i,j in re:
            return_+=(i-last)*(n-j)
            last=i
        return return_
```