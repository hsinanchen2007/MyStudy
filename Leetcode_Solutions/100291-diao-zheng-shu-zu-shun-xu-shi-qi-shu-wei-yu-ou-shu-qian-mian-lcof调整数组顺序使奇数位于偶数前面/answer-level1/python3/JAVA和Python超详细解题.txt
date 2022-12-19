这道题的核心逻辑就是将数据进行分堆处理，这里笔者首先考虑到的做法是，可以再定义一个数组，和原数组一样的长度；并且定义两个指针left和right分别指向新数组的开头和结尾；

然后遍历原数组，如果是奇数，就赋值给新数组的left位，然后left++，如果是偶是，就赋值给新数组的right位，然后right--，直到left >= right，新数组就是满足我们要求的所有奇数位于数组的前半部分，所有偶数位于数组的后半部分的数组；

这么做我们只遍历了一遍数组，但是定义了一个和原数组一样长度的新数组，空间复杂度和时间复杂度都是O(n);

---
左右指针法：

我们同样可以定义两个指针left、right指向原数组的左右两端；

然后左右两个指针同时向中间移动，直到左指针碰到了偶数，右指针碰到了奇数（注意左右指针不要移出了数组，导致空指针异常），此时如果左指针在右指针的左边，左右指针的元素交换，一直到左指针到了右指针右边，说明已经交换完毕；

这样做时间复杂度是O(n)、空间复杂度是O(1);


## 代码（JAVA、Python3实现）
ps：这里笔者使用的jdk为1.8版本、python使用的3.7版本

- java实现
```java
class Solution {
    public int[] exchange(int[] nums) {
        if (Objects.isNull(nums) || nums.length < 2) {
            return nums;
        }
        int left = 0;
        int right = nums.length - 1;

        while (true) {
            while (left < nums.length && nums[left] % 2 != 0) {
                left++;
            }
            while (right >=0 && nums[right] % 2 == 0) {
                right--;
            }
            if (left < right) {
                /* 交换位置 */
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            } else {
                break;
            }
        }
        return nums;
    }
}
```

- python实现（刚学了两天python，用python写把练练手）
```python
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
            if nums is None or len(nums) < 2:
                return nums
            left = 0
            right = len(nums) - 1
            while True:
                while left < len(nums) and nums[left] % 2 != 0:
                    left += 1
                while right >= 0 and nums[right] % 2 == 0:
                    right -= 1
                if left < right:
                    nums[left], nums[right] = nums[right], nums[left]
                else:
                    break
            return nums
```