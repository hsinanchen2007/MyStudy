
## 方法1：正推法
对于**bits**数组从左到右作线性扫描来判断最后一位是否为**一个一比特字符**.当扫描到第i位时,如果**bits[i]=1**,那么说明为一个两比特字符,将**i**的值增加2;如果**bits[i]=0**,那么说明为一个一比特字符,将**i**的值增加1

如果i最终落在**len(bits)-1**的位置,那么说明最后一位一定是一比特字符

![1.png](https://pic.leetcode-cn.com/e8ebea834e72b1513a21f14ab0a6f63d7aac830a604cb5632b13854b53d02817-1.png)

![2.png](https://pic.leetcode-cn.com/45cfc5c125c0a8ac94e88390f533195c43a31aabbed3ca423cf58feef1c29fd4-2.png)

**代码如下**：

```python
class Solution:
    def isOneBitCharacter(self,bits):
        """
        :param bits: List[int]
        :return: bool
        """
        i=0
        while i<len(bits)-1:
            i+=bits[i]+1
            
        return i==len(bits)-1
```

**复杂度分析**：
- 时间复杂度：O(n),其中**n**是bits数组的长度
- 空间复杂度：O(1)

## 方法二：倒推法

由于**bits[len(bits)-1]=0**,我们需要统计其前面多少个1是连续的,用**count**来计数;

![3.png](https://pic.leetcode-cn.com/41c48b1980fd64121a25792287f823ba1ea22389124130df13da1af763387427-3.png)

1. count%2==0:

    以一个一比特字符结尾
2. count%2!=0:

    以一个两比特字符结尾

**代码如下**：
``` python
class Solution:
    def isOneBitCharacter(self,bits):
        """
        :param bits: List[int]
        :return: bool
        """
        size = len(bits)

        if bits[size - 2] == 0:
            return True
        else:
            count = 0
            i = size - 2

            while i >= 0 and bits[i] == 1:
                i -= 1
                count += 1

            if count % 2 == 0:
                return True
            else:
                return False


```


