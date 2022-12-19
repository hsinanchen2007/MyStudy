### 解题思路


### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        if (nums.length < 2){return;}
        int n = nums.length - 1;
        int idPos = n - 1;

        // 寻找idPos
        while(idPos >= 0 && nums[idPos] >= nums[n]){
            idPos--;
            n--;
        }

        // idPos == -1 表示数组序最大，不需要交换；反之，在idPos右侧寻找最小的大于num[idPos]的元素下标n，并交换。
        if (idPos >= 0){
            n = nums.length - 1;
            while(nums[n] <= nums[idPos]){
                n--;
            }

            swap(nums, idPos, n);
        }

        // 逆置，从idPos + 1到nums.length
        for (int i = 0; i < (nums.length - 1 - idPos) / 2; i++){
            swap(nums, idPos + 1 + i, nums.length - 1 - i);
        }

        return;
    }

    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
}
```