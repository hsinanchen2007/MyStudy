### 解题思路
看注释

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int p0=0,p2=nums.length-1,cur=0;//分别为0的右边界，2的左边界，当前下标。
        while(cur<=p2){
            if(nums[cur]==0){
                swap(nums,cur,p0); 
                p0++;
                cur++; //与前面进行交换，可知从前面交换回的数值必为0或1（因为如果是2，已经进行处理），
                        //所以这里cur++
            }else if(nums[cur]==2){
                swap(nums,cur,p2);  
                p2--;    //与后面进行交换，换回的数字未知，所以cur不能+1，要再进行一轮判断
            }else{
                cur++;
            }
            
        }  
    }
    public void swap(int nums[],int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}
```