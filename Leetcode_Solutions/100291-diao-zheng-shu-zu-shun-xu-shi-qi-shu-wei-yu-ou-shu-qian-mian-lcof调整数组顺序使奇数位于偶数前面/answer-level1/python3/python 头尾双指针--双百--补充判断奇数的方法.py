### 解题思路
    ex： [1,2,3,4]

    流程：
        ①顺序读取，直至读取到偶数2
        ②交换2与数组最后一位数字，即[1,4,3,2]。此时end指向3
        ③4仍未偶数，交换4与3的位置。[1,3,4,2]。此时end与start相交，返回nums

    奇数判断补充：yiwei
        ①取余：与2相除。在计算上较慢
        ②移位：number = number >>1 <<1。 较为繁杂，略快于①
        ③与操作：直接于1进行与操作，简洁，高效



    
#### 实际效果：
![下载 (7).png](https://pic.leetcode-cn.com/95647ffa263e8d726db6e2a412bd5dec4f607eeced921a27ae63cbac5fd1f922-%E4%B8%8B%E8%BD%BD%20\(7\).png)


### 代码

```py
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        end = len(nums)-1
        start = 0
        while start <= end:
            if (nums[start] & 1):                    #顺序读取，直至读取到偶数
                start += 1
            else:
                #while里的内容可以不加
                #加入while结构后，程序处理[1,4,5,7,9,2,4,6,8,12]基本奇数在前，偶数在后的数组，会有明显的速度提升
                while (not (nums[end] & 1)) and start < end:     
                    end -= 1                            
                nums[start], nums[end] = nums[end], nums[start]
                end -= 1
        return (nums)
        
```