### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        //定义一个新数组只存两个数
        int[] Array=new int[2];
        //遍历数组nums
        for(int i=0;i<nums.length;i++)
        {
           for(int j=i+1;j<nums.length;j++)
           {
            //如果一个数的值等于target减去另一个数的值
               if(nums[i]==target-nums[j])
                {
                    //将两个数的值依次赋给新数组Array
                    //跳出for循环
                    Array[0]=i;
                    Array[1]=j;
                    break;
                }
           } 
        }/输出新数组Array
        return Array;
    }
}
```