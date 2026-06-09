```java
class Solution {
    public boolean isStraight(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int min = 20;
        int max = -10;
        int cnt = 0; // 0的个数
        for(int i=0 ; i<5 ; i++){
            if(nums[i] == 0){
                cnt++;
                continue;
            }
            if(set.contains(nums[i])){
                //出现重复
                return false;
            }
            set.add(nums[i]);
            min = Math.min(min,nums[i]);
            max = Math.max(max,nums[i]);
        }
        
        return (max-min+1) <= (set.size()+cnt);
    }
}
```
