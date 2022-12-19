### 解题思路
此处撰写解题思路
思路就是简单的分治法解决问题
左右分别定义表示位置的指针left  right
算出此时数组的中间位置
中间位置与target进行比较

单纯为了打卡写的题解  只是为了自己能看懂~~~~
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        int mid = 0;
        while(left <= right){
            mid = (left + right)/2;
            if(target == nums[mid]) return mid;
            if(target > nums[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
}
```