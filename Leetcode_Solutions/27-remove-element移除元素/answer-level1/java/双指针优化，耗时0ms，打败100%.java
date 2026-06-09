### 解题思路
双指针进行判断，先判断tail尾部元素，找到第一个不为val的元素
而后使用head指针，从头部遍历，找到为val的元素后，与tail元素交换
交换之后，判断tail--的元素，找到不为val的元素位置，在进行正序的遍历
最后返回值为从tail尾部指针+1，长度
当用例为[2,2,2,2,2] 2 时
因为执行中tail为-1，所以最终返回0，也是正确的。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if (null == nums || nums.length == 0) {
            return 0;
        }
        int tail = nums.length - 1;
        while (tail >= 0) {
            if (nums[tail] == val) {
                tail--;
            } else {
                break;
            }
        }
        int head = 0;
        while (head < tail) {
            if (nums[head] == val) {
                swap(nums, tail, head);
                //判断tail--的值
                do {
                    tail--;
                } while (nums[tail] == val);
            }
            head++;
        }

        return tail + 1;
    }
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```