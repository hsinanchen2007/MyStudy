一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
这题主要考时间复杂度，所以一定要二分。二分对比的点一定得是最右边的点，最左边的会有很多bad case。

### 代码

```python
class Solution(object):
    def minArray(self, numbers):
        low, high = 0, len(numbers) - 1
        while low < high:
            mid = (high+low) / 2
            if numbers[mid] > numbers[high]:
                low = mid + 1
            elif numbers[mid] < numbers[high]:
                high = mid
            else:
                if (numbers[high - 1] > numbers[high]):  # 确保正确的下标
                    low = high
                    break
                high -= 1  # 如果numbers[hign-1]=numbers[high]的情况
        return numbers[low]

```