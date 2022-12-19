### 解题思路


### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums.length == 0 || nums.length < 3) return 0;
        Arrays.sort(nums);
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.length;i++){
            int l = i+1;
            int r = nums.length-1;
            while(l < r){
                int sum = nums[i]+nums[l]+nums[r];
                if(Math.abs(target-sum) < Math.abs(target-ans)){// 有正有负，需要使用绝对值进行处理
                    ans = sum;
                }
                if(sum > target){  
                    r--;
                }else if(sum < target){
                    l++;          
                }else{
                    return sum;// ans = sum;  相等的时候直接进行返回就可以
                } 
            }
        }
        return ans;// 返回最接近的那个值
    }
}
```