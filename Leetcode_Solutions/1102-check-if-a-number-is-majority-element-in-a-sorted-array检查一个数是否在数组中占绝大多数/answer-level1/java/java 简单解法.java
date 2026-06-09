```java
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        /*
        因为占绝大多数，是指在长度为 N 的数组中出现必须 超过 N/2 次。
        所以，数组中间位置的值才有可能是占绝大多数的值。步骤如下：
        1.找到数组中间位置的值middle
        2.从中间位置分别向数组左边，右边遍历找到所有和middle相等的数字
        3.统计这些数字的数量，如果大于数组长度的一半则找到。
        */
        int len = nums.length;
        int middle = nums[len / 2];
        
        int i = len / 2, j = len /2 + 1;
        while(i >= 0){
            if(nums[i] != target) break;
            i--;
        }
        
        while(j < len){
            if(nums[j] != target) break;
            j++;
        }
        
        int cnt = j - i - 1;
        return cnt > len/2;
    }
}
```