### 解题思路

一个数res代表当前众数
一个数count代表当前众数的出现次数绝对值（当前众数出现次数-其他数出现次数）

那么！！
当count=0的时候，当前众数出现次数和其他数出现次数相等，那么！在剩下的没有遍历的数中，众数还是出现了更多次！！！

所以count等于零的时候，从当前位置开始重新开始以前的计数方法（当前众数设置为下一个数，count设置为1）
（类似递归思路）


### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if(nums.length==1 || nums.length==2){
            return nums[0];
        }
        int res = nums[0];
        // 当前候选人票数
        int count = 1;
        for(int i=1;i<nums.length;i++){
            if(count==0){
                // 如果当前候选人得票绝对值为0，则重新来过！
                res = nums[i];
                count = 1;
            }else{
                if(nums[i]==res){
                    count++;
                }else{
                    count--;
                }
            }
        }
        return res;
    }
}
```