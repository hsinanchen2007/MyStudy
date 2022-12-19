### 解题思路

### 代码

```java
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
    Arrays.sort(nums);
    int res = 0;
    //int count = 0;
    for(int i =0;i<nums.length;i++){
        int left =i+1;
        int right=nums.length-1;
        while(left<right){
        int sum = nums[i]+nums[left]+nums[right];
        if(sum<target){
            //同时统计多个结果，因为是有序，right左边的都可以满足
            res=res+right+-left;
            left++;
        }
        else{
            right--;
        }
        }
    }
    return res;
    }
}
```