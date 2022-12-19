真正的O(n)时间复杂度

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        int ans = 0;
        Map<Integer,Integer> m = new HashMap();
        for(int i=0;i<nums.length;i++){
            if(m.containsKey(nums[i]) ){
                continue;
            }else{
                if(m.containsKey(nums[i]+1)&&m.containsKey(nums[i]-1)){
                    int tmp = m.get(nums[i]+1) + m.get(nums[i]-1) +1;
                    m.put(nums[i],m.get(nums[i]+1) + m.get(nums[i]-1) +1 );
                    m.put(nums[i]+m.get(nums[i]+1),tmp);
                    m.put(nums[i]-m.get(nums[i]-1),tmp);
                    if(tmp>ans){
                        ans = tmp;
                    }
                }
                else if(m.containsKey(nums[i]+1)){
                    int tmp = m.get(nums[i]+1)+1;
                    m.put(nums[i],m.get(nums[i]+1)+1);
                    m.put(nums[i]+m.get(nums[i]+1),tmp);
                    if(tmp>ans){
                        ans = tmp;
                    }
                }else if(m.containsKey(nums[i]-1)){
                    int tmp = m.get(nums[i]-1)+1;
                    m.put(nums[i],m.get(nums[i]-1)+1);
                    m.put(nums[i]-m.get(nums[i]-1),tmp);
                    if(tmp>ans){
                        ans = tmp;
                    }
                }
                else{
                    m.put(nums[i],1);
                    if(1>ans){
                        ans = 1;
                    }
                }
            }
        }
        return ans;
    }
}
```
