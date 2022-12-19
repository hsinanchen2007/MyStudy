执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
89.16%
的用户
内存消耗 :
36.3 MB
, 在所有 Java 提交中击败了
85.29%
的用户
```
class Solution {
    public int search(int[] nums, int target) {
        if(nums.length==0)return -1;
        return get(nums,target,0,nums.length-1);
    }
    private int get(int[] nums, int target, int start, int end){
       // System.out.println(start+"_"+end);
        if(start==end ){
            if(nums[start]==target){
                return start;
            }else{
                return -1;
            }
        }
        int middle = (end+start)/2;
        if(nums[middle]==target)return middle;
        if(nums[start]==target)return start;
        if(nums[end]==target)return end;
        if(nums[middle]>nums[end]){
            if(target<nums[middle]&& target>nums[start] && middle-1>start){
                 return get(nums,target,start+1, middle-1);
              
            }else if(end>middle+1){
                 return get(nums,target,middle+1,end);
            }else{
                return -1;
            }
        }else{
           if(target>nums[middle]&& target<nums[end] && end>middle+1){
                return get(nums,target,middle+1,end-1);
            }else if(middle-1>start){
                return get(nums,target,start, middle-1);
           }else{
               return -1;
           }
        }
        
    }
}
```
