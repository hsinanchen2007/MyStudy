### 解题思路
通过提示我们可以容易想到头尾各用一个指针，然后一次遍历，遇到红色就与头部置换，遇到蓝色就与尾部置换，其中遇到蓝色时，需要判断尾部之前为红色的场景，此时通过将index
减一，可以避免代码添加额外判断。

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int redIndex = 0;
        int blueIndex = nums.length - 1;
        for (int index = 0; index <= blueIndex; index++) {
            if (nums[index] == 0) {
                swap(nums, redIndex, index);
                redIndex++;
            }

            if (nums[index] == 2) {
                swap(nums, blueIndex, index);
                blueIndex--;
                index--; // 
            }
        }
    }

    private void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
}
```