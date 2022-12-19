执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
98.75%
的用户
内存消耗 :
35.9 MB
, 在所有 Java 提交中击败了
35.88%
的用户
```
class Solution {
    public void sortColors(int[] nums) {
        int i1 = -1;
        int i2 = -1;
        
        for(int i=0; i<nums.length; i++){
            int x = nums[i];
            if(x==0){
                if(i2!=-1){
                    nums[i2++]=0;
                    nums[i]=2;
                     if(i1!=-1){
                        nums[i2-1]=1;
                        nums[i1++]=0;
                    }
                }else if(i1!=-1){
                    nums[i]=1;
                    nums[i1++]=0;
                }
            }else if(x==1){
                if(i1==-1){
                    i1=i;
                }
                
                if(i2!=-1){
                    nums[i2++]=1;
                    nums[i]=2;
                    if(i1==i){
                        i1=i2-1;
                    }
                }
                
            }else if(x==2){
                if(i2==-1)i2=i;
            }
        }
    }
}
```
