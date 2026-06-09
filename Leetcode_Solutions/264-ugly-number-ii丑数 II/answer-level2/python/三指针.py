### 解题思路
此处撰写解题思路
当我们已经知道前n个丑数时，如何获得第n+1个丑数？
我们可以确定的是第n+1个丑数总可以表示为2A或3B或5C
所以我们可以从前n个丑数中挑出3个数，分别乘以2,3,5
比较结果，取最小的一个作为第n+1个丑数
不妨用index这个大小为3的列表来储存挑出的三个数的指标
那么现在问题就在于如何挑出这三个数，也就是如何维护index
要满足的条件是：
1.要保证这三个数分别乘以2 3 5后，其中的最小那个记作cur,它一定得大于第n个丑数（等价于要求乘完之后，每个都得大于第n个丑数）
2.要保证在cur与第n个丑数之间，不存在别的丑数

假定我们已经知道了前n个丑数时候的index是满足这两条要求的
cur=min(2*ugly[index[0]],3*ugly[index[1]],5*ugly[index[2]])
此时我们就得到了第n+1个丑数为cur,ugly.append(cur)
1.现在我们判断一下，若cur=2*ugly[index[0]],则index[0]+=1
  这保证了新的index能够满足之前提到的第一点要求
2.而因为新的index相较于之前的index的每一个位置，最多只会+1
所以自然保证了第二条要求

n=1时ugly=[1]，此时index只能为[0,0,0]




### 代码

```python3
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        index=[0,0,0]
        ugly=[1]
        for i in range(1,n):
            a=ugly[index[0]]*2
            b=ugly[index[1]]*3
            c=ugly[index[2]]*5
            cur=min(a,b,c)
            if cur==a:
                index[0]+=1
            if cur==b:
                index[1]+=1
            if cur==c:
                index[2]+=1
            ugly.append(cur)
        return ugly[-1]
        
```