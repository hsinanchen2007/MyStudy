### 解题思路
    二分查找法：
    （1）如果当前数字与当前位置相等，则说明前面的数字都没有缺失，直接继续对后面的数字进行二分查找
    （2）如果当前数字与当前位置不相等，则说明前面的数字有缺失，直接继续对前面的数字进行二分查找

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
       
        int low =0,high = nums.length-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == mid){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;

    }
}
```