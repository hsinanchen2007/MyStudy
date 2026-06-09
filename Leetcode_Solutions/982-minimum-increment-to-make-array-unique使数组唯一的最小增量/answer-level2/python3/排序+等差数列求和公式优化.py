### 解题思路
首先利用桶排序的概念对原来的数据进行统计，得到每个数的出现次数。
然后对数据进行排序.
例如:
[3,2,1,2,1,7]
则得到计数器:
{
    1:2
    2:2,
    3:1
    7:1
}
我们此时从小到大做处理，如果每次在这个计数器末尾增加一个新的数据应该怎么做？
当前我们认为，如果只有 {1:2}的情况下,那么需要将其中的一个1增加1，变成2。此时有效。
那么此时{1:2} => {1:1,2:1}
此时增加{2:2} 意味着2位置已经被占据了，所以新增的位置要从3开始，则应该是
2===>3
2===>4
所以得到新的:
{
1:1,2:1,3:1,4:1
}
所以代码应该为:

```
num = -1 # 应该安放的位置
for k in kk:
    if num < k:
        num = k

    # 新的counter[k]个数据大小为k的值，占据的位置数量
    # 从num开始，每个数占据一个位置
    for i in range(0, counter[k]):
        move += num - k
        num += 1
```
然后我们对于上面那个for循环进行优化即可得到下面的的公式.
因为上面那个相当于:
num - k + (num - k + 1) + .... + (num - k + counter[k] - 1)
所以相当于:
(num - k) * counter[k] + (0 + 1 + 2 + ... + counter[k] - 1)
即: (num - k) * counter[k] + (counter[k] * (counter[k] - 1) // 2)

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        counter = {}
        for a in A:
            if a not in counter.keys():
                counter[a] = 0
            counter[a] += 1
        
        kk = counter.keys()
        kk = sorted(kk)
        move = 0
        num = -1
        for k in kk:
            if num < k:
                num = k
            move += (num - k) * counter[k] + counter[k] * (counter[k] - 1) // 2
            num += counter[k]
        return move
            
            
            
            
```