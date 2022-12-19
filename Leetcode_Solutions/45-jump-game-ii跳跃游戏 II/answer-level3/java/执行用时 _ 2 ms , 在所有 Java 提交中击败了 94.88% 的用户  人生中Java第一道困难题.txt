### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        int count=0;
        int max=0;
        int number=0;
        //开始阶段判断是否已为数组最后位置
        if(count==nums.length-1){
            return 0;
        }
        while (true){
             number++;
            //判断当前点是否直接能够到达数组最后位置
            if(count+nums[count]>=nums.length-1){
                return number;
            }else{
                //找出在此点跳跃范围之内能跳到最远的位置位置索引
                for(int j=count;j<=count+nums[count];j++){
                    max=j+nums[j]>max+nums[max]?j:max;
                }
                count=max;
            }
        }
    }
}
```