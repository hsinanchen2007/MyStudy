### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        // 从后往前找, 直到有最后一个a[i+1] > a[i]的, 此时表明这个字符是大的, 如果逆序后会变大
        // 从i+1开始, 向后搜索, 找到一个最小的比a[i]大的, 交换, 这样可以保证是下一个字典序
        // 同时后面的都是逆序的, 需要全部变为为正序
        int index = nums.length - 2;
        while(index >= 0 && nums[index+1] <= nums[index]){ // 找到第一个为正序的即可
            index--;
        }
        // 1 3 8 4 7 6 5 1 => 1 3 8 5 7 6 4 1
        if(index >= 0){ // 如果此时index>=0表明还存在某个元素是正序, 否则所有的都是逆序
            int j = nums.length - 1;
            while(j > index && nums[j] <= nums[index]){ // 找到第一个比index元素大的元素, 交换
                j--;
            }
            swap(nums, index, j);
        }
        // 将[index+1, ... , n-1]的变为正序, 因此如果index=-1, 即变为最小的字典序: 正序排列
        int left = index+1, right = nums.length - 1;
        while(left < right){
            swap(nums, left, right);
            left++;
            right--;
        }
    }
    void swap(int[] nums, int i, int j){
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }
}
```