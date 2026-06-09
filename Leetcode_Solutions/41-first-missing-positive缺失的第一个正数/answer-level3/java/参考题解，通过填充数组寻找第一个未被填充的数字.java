执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
89.29%
的用户
内存消耗 :
35.3 MB
, 在所有 Java 提交中击败了
85.53%
的用户
```
class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        if(len==0)return 1;
        boolean one=false;
        //-1 empty, -2 occupy
        for(int i=0;i<len; i++){
            if(nums[i]>len||nums[i]<=0){
                nums[i]=-1;
            }
        }
        for(int i=0;i<len; i++){
            setup(nums,i,len);
        }
        int j=len;
        for(int i=0;i<len; i++){
            if(nums[i]==-1){
                j=i;
                break;
            }
        }
        return j+1;
    }
    private void setup(int[] nums, int i, int len){
        int k = nums[i];
        if(k==-1||k==-2){
            return;
        }else{
            nums[i]=-1;
            setval(nums,k);
        }
    }
    private void setval(int[] nums,int k){
        if(nums[k-1]==-1||nums[k-1]==-2){
            nums[k-1]=-2;
        }else{
            int x = nums[k-1];
            nums[k-1]=-2;
            setval(nums,x);
        }
    }
}
```
