### 解题思路
优点类似快排的思路，取数组两头的值做为双指针初始值，然后两边进行夹逼，最后找到一对值。
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
    if(nums==null||nums.length==0){
        return nums;
    }
    int low=0;
    int high=nums.length-1;
    while(low<high){
        int temp= nums[low]+nums[high];
        if(temp>target){
            high--;
        }else if(temp<target){
            low++;
        }else{
            int[] sum=new int[2];
            sum[0]=nums[low];
            sum[1]=nums[high];
          return sum;
        }
    }
    return new int[0];
    }
}
```