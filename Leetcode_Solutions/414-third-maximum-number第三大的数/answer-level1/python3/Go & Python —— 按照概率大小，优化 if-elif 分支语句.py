### Go
![153f90c28bb6cf12fc858763863e3e2.png](https://pic.leetcode-cn.com/a8a80c27bbe6a96ac4ee1dc4b9e89cd79adc6ac1d8b60e828a45e67d6df7f451-153f90c28bb6cf12fc858763863e3e2.png)
### Python
![c42def21922e5c4bd19af4e86cbcdcb.png](https://pic.leetcode-cn.com/d9751662430ec0b02ca549505efbbc3def9d8d1f9f1e6f4b91c54f227d87ac55-c42def21922e5c4bd19af4e86cbcdcb.png)
### 几个注意点
1.本题的基本思路是维护3个值，分别代表最大、第二大和第三大的数。当然你也可以维护一个长度为3的数组。这两者在本质上没有任何区别
2.本题有去重的要求，可以用集合实现，但会产生额外O(n)的空间开销。也可以像下面代码这样，通过if判断去重，那就只有O(1)额外空间开销
3.因为这3个数是排序的，很自然地会想到维护一个长度为3的数组，然后用binary insert来维护。这样的话对于nums里的每个num：会先和第二大的比较，再根据比较结果，和第一大或第三大的比较（大概率是跟第三大的比较），每个数实际经历上2次比较。

注意：这不是个好的思路！好的思路参照第4点

4.如果n个数是随机的，可以在若干次后，很快得到比较大的三个数。此时后面的数应该先和第三个数比较，因为数学期望上，它比第三个数小的可能性大于0.5，所以就被挡在门外。这样的话大部分的情况下，只需要一次比较。这个有点像闯关比赛，第三个数是第一关，第二个数是第二关，第一个数是最后一关。如果这些数是正态分布的话，那么每一关闯不过的可能性大于闯过。

下面就是根据概率大小写的代码，可以尽可能减少if语句的判断次数。
### 代码

```go []
import "math"

func thirdMax(nums []int) int {
	first, second, third := math.MinInt64, math.MinInt64, math.MinInt64
	for _, num := range nums {
		if num > third { // 通过第3关
			if num < second {
				third = num
			} else if num > second { // 通过第2关
				if num < first {
					third = second
					second = num
				} else if num > first { // 通过第1关
					third = second
					second = first
					first = num
				}
			}
		}
	}
	if third == math.MinInt64 {
		return first
	} else {
		return third
	}
}

```
```python []
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        first = second = third = float('-inf')
        for num in nums:
            if num > third:  # 通过第3关
                if num < second:
                    third = num
                elif num > second:  # 通过第2关
                    if num < first:
                        third = second
                        second = num
                    elif num > first:  # 通过第1关
                        third = second
                        second = first
                        first = num
        if third == float('-inf'):
            return first
        else:
            return third

```