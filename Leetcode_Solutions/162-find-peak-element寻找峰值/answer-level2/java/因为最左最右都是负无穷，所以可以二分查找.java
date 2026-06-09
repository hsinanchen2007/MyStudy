执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
91.25%
的用户
内存消耗 :
38.7 MB
, 在所有 Java 提交中击败了
32.98%
的用户
```
class Solution {
    public int findPeakElement(int[] nums) {
        int len = nums.length;
        if(len==0)return 0;
        if(len==1)return 0;
       return get(nums,0,len);
    }
    private int get(int[] nums,int s, int e){
        if(s==e)return s;
        int i = (e+s-1)/2;
        if(i+1>nums.length-1){
            return i;
        }
        
        if(nums[i]<nums[i+1]){
            return get(nums,i+1,e);
        }else{
            return get(nums,s,i);
        }
    }
}
```
