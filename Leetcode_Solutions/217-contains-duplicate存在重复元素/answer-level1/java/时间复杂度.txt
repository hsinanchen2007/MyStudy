### 解题思路
此处撰写解题思路
我的思路:
    时间复杂度真的很重要的，关键就看你用什么算法，什么算法快的话就不会超出时间限制了
### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        int n=0;
           for(int g=nums.length/2;g>=1;g/=2){
               for(int i=g;i<nums.length;i++){
                   int j=i;
                   int temp=nums[j];
                   while(j-g>=0 && temp<nums[j-g]){
                       n=temp;
                       nums[j]=nums[j-g];
                       j-=g;
                   }
                   nums[j]=temp;
               }
           }
            for(int i=0;i<nums.length-1;i++){
                if(nums[i]==nums[i+1]){
                    return true;
                }
            }
            return false;
    }
}
```