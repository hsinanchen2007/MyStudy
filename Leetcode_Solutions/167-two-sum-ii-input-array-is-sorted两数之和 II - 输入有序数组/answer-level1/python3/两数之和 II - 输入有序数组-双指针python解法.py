根据官方题解的思路，

使用两个指针，初始分别位于第一个元素和最后一个元素位置，比较这两个元素之和与目标值的大小。如果和等于目标值，我们发现了这个唯一解。如果比目标值小，我们将较小元素指针增加一。如果比目标值大，我们将较大指针减小一。移动指针后重复上述比较知道找到答案。

python代码如下：
```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # 定义low，high指针分别处在数组两端 
        low,high = 0,len(numbers) - 1
        while low < high:
            # 如果两指针之和为target值，返回索引+1
            if numbers[low] + numbers[high] == target:
                return low + 1,high + 1
            # 如果两指针指向值之和大于target值，high指针左移
            elif numbers[low] + numbers[high] > target:
                high -= 1
            # 如果两指针指向值之和小于target值，low指针右移
            else:
                low += 1
```
**复杂度分析**
- 时间复杂度：O(N)，每个元素被遍历一次
- 空间复杂度：O(1)，只用了双指针，占用常数级空间。

![白色背景关注.jpg](https://pic.leetcode-cn.com/47d1b5430e869ed420bb0c6e8a90250773528ccf1bf6d4d43aef80dd326eeef9-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
