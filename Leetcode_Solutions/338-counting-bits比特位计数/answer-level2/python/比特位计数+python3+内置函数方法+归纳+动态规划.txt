### bin内置函数

思路很简单，基本上一目了然，时空复杂度貌似还行。直接贴代码。

```
class Solution:
    def countBits(self, num: int) -> List[int]:
        target = []
        for i in range(num+1):
            count = bin(i).count('1')
            target.append(count)
            
        return target
```

### 归纳法

思路就是找规律，其实也是动态规划的基础，时间复杂度比上面的要好，空间复杂度很好。基本规律如下：
| 数字  | 其中‘1’的个数 |
| --- | --- |
| 0 | 0 |
| 1 | 1 |
| 2 | 1（数字0的时候加1） |
| 3 | 2（数字1的时候加1）|
| 4 | 1（数字0的时候加1） |
| 5 | 2（数字1的时候加1） |
| 6 | 2（数字2的时候加1） |
| 7 | 3（数字3的时候加1） |
| ... | ... |

其实就是对于一个二级制数——1XXXX，它的所有的组合方式就是XXXX位数有多少个。直接贴代码:
```
class Solution:
    def countBits(self, num: int) -> List[int]:
        target = [0]
        n = len(target)
        while n<=num+1:
            for i in range(n):
                target.append(target[i]+1)     
            n = len(target)
        return target[0:num+1]                
```

### 动态规划

类似于上面找的规律，就是每一个数等于它前面第2^x次方的数加1，这个x是需要确定的。代码如下：

```
class Solution:
    def countBits(self, num: int) -> List[int]:
        target = [0]
        count1 = 1 
        count2 = 1
        for i in range(1,num+1):
            if count2 == 0:
                count1 *= 2
                count2 = count1-1
                target.append(target[i-count1]+1)
            else:
                target.append(target[i-count1]+1)
                count2 -= 1
        return target
                
```

如有疑问请评论区评论或者邮箱anzhengyu@sjtu.edu.cn，共同探讨！