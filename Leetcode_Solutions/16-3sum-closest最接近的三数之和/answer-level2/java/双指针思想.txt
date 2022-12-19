转换为双指针思想：
- 升序排列；
- 转换为|nums[a] + nums[b] + nums[c] - target|无限趋近于0；
- 固定指针a，双指针b，c策略；

> 与15题“三数之和”类似
```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums.length<3){
            throw new IllegalArgumentException("argument error");
        }
        
        Arrays.sort(nums);
        
        int min = Integer.MAX_VALUE;
        int data = 0;
        for(int i=0;i<nums.length;i++){
            int m=i+1,n=nums.length-1;
            while(m<n){
                int sum = nums[i]+nums[m]+nums[n];
                int gap = sum - target;
                if(gap==0){
                    return target;
                }
                if(gap<0){
                    m++;
                }else{
                    n--;
                }
                if(Math.abs(gap)<min){
                    data = sum;
                    min=Math.abs(gap);
                }
            }
        }
        
        return data;
        
    }
}
```