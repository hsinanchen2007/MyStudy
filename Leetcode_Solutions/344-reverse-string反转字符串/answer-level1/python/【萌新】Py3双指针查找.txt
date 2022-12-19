### 解题思路
核心：双指针查找，每次指针移动就交换对应索引的元素
分情况讨论：列表长度奇数，直接查找，最后也就是中位的元素不需要改变
            列表长度偶数，查找到i和u的差等于1时停止，此时还有中间的2个元素未交换位置，单独进行交换
            列表长度0，返回[]即可。

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        singal=len(s)
        i=0
        u=singal-1
        if singal%2==1:
            while i!=u:
                mid=s[i]
                s[i]=s[u]
                s[u]=mid
                i+=1
                u-=1
        elif singal%2==0 and singal!=0:
            while abs(i-u)!=1:
                mid=s[i]
                s[i]=s[u]
                s[u]=mid
                i+=1
                u-=1
            mid=s[i]
            s[i]=s[u]
            s[u]=mid
        elif s==[]:
            return [] 
```