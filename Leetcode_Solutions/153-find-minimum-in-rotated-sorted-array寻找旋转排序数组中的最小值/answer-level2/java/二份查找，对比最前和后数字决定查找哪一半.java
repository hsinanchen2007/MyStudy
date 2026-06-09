执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
98.86%
的用户
内存消耗 :
36.4 MB
, 在所有 Java 提交中击败了
40.49%
的用户
```
class Solution {
    public int findMin(int[] nums) {
        int len = nums.length;
        if(len==1)return nums[0];
        return get(nums,0,len-1);
    }
    private int get(int[] nums,int s,int e){
        //if(s==e)return nums[s];
        if(e-s==1)return Math.min(nums[s],nums[e]);
        int m = (s+e)/2;
        if(nums[m]>nums[s]){
            if(nums[m]>nums[e]){
                 return get(nums,m,e);
            }else{
                return nums[0];
            }
           
        }else if(nums[m]<nums[e]){
            return get(nums,s,m);
        }
        return -1;
    }
}
```
