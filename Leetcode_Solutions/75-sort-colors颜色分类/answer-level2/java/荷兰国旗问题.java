### 解题思路
思路和快排有点类似，因输入只有 0,1,2 三种值，可以直接判断当前遍历的节点状态，所有的 0 需要放到最左边，
所有的 2 需要放到最右边，有两个指针 left 和 right 分别表示 0 和 2 能够放置的开始位置，放一个 0 后 left++,
放一个 2 后 right--；使用 i 遍历数组(从 0 开始)，因为最右边已经都归位了，所以 i <= right 即可。

### 代码

```java
class Solution {
    
    public void swap(int[] nums, int i , int j) {
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }

    public void sortColors(int[] nums) {
        if (nums == null || nums.length <= 1) return;
        int left = 0, right = nums.length - 1, current = 0;
        for (int i = 0; i <= right;) {
            if (nums[i] == 2) {
                swap(nums, i, right);
                right--;
                continue;
            }

            if (nums[i] == 0) {
                if (i != left) {
                    swap(nums, i, left);
                }
                left++;
            }
            
            i++;
        }
    }
}
```