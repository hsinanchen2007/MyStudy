预设布尔型标签flag，默认值为false，如果出现匹配的元素，就将flag赋值为true，如果跳出for循环之后还为false，则证明无匹配，此时执行返回索引，方法比较简单，但不够简洁，适合初学者，欢迎探讨

```
class Solution {
    public int searchInsert(int[] nums, int target) {
        boolean flag = false;
        int a,b = 0;
        for(int i = 0;i < nums.length ;i++)
        {if(target == nums[i])
         {   flag = true;
             return i;}//if
         }//for
       
        if(flag == false){
            for(int j =0;j < nums.length ;j++){
                if(target > nums[j]){
                    if(j==nums.length-1)
                    {b=nums.length;}}
                else{
                     b = j;
                     break;
                   
                }//else
            }//for
        }//if
       return b;
    }//public
}//class
```
