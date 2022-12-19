执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
99.33%
的用户
内存消耗 :
37.4 MB
, 在所有 Java 提交中击败了
87.99%
的用户
```
class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        if(len==0||len==1)return ;
       
        boolean done=false;
        for(int i=len-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                done=true;
                int ind = len-1;
                for(int k=i+1; k<len; k++){
                   if(nums[i]>=nums[k]){
                       ind = k-1;
                       break;
                   }
               }
                int temp = nums[i];
                nums[i]=nums[ind];
                nums[ind]=temp;
                
                quickSort(nums,i+1,len);
                break; 
            }
        }
        if(!done){
             quickSort(nums,0,len);
        }    
        
    }
    
   
    private void quickSort(int[] nums, int start, int end){
      //  System.out.println(start+"+"+end);
        if(start>=end-1)return ;
        int ref = nums[start];
        int i=start+1;
        for(int j=start+1; j<end;j++){
            if(nums[j]<ref){
                if(i<j){
                    int t = nums[j];
                    nums[j]=nums[i];
                    nums[i]=t;
                   
                }
                 i++;
            }
        }

        int t = nums[i-1];
        nums[i-1]=nums[start];
        nums[start]=t;

        quickSort(nums,start,i-1);
        quickSort(nums,i, end);
        
        
    }
}
```