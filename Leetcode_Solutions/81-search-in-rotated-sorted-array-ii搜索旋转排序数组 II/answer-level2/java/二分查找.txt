执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
98.80%
的用户
内存消耗 :
39.5 MB
, 在所有 Java 提交中击败了
13.70%
的用户
```
class Solution {
    public boolean search(int[] nums, int target) {
        
        if(nums.length==0)return false;
        
        return get(nums,0,nums.length-1,target);
    }
    private boolean get(int[] nums, int s, int e, int t){
        int m = (s+e)/2;
        if(s>e)return false;
        if(s==e){
            if(nums[s]==t){
                return true;
            }else{
                return false;
            }
        }
        if(nums[m]==t){
            return true;
        }
        while(nums[m]==nums[s]&&s!=m){
            s++;
        }
        while(nums[m]==nums[e]&&m!=e){
            e--;
        }
        if(m==s){
            return get(nums,m+1,e,t);
        }
        if(m==e){
            return get(nums,s,m-1,t);
        }
        if(nums[m]<t){
            if(nums[m]>nums[s]||(nums[m]<nums[s]&&t<nums[s])){
                return get(nums,m+1,e,t);
            }else{
                return get(nums,s,m-1,t);
            }
        }else{
            if(nums[m]<nums[e]||(nums[m]>nums[e]&&t>nums[e])){
                return get(nums,s,m-1,t);
            }else{
                return get(nums,m+1,e,t);
            }
        }
    }
}
```
