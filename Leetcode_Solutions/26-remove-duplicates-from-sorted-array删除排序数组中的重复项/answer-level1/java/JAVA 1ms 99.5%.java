### 解题思路


### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length<1){
            return 0;
        }
        int c=1;//下标指向数字的后一位
        int tmp=nums[0];//辅助变量
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=tmp){//不匹配时
                tmp=nums[i];//记录该数字
                nums[c]=tmp;//放在下标为c的位置
                c++;//下标后移一位
            }
        }
        //返回c，即处理后输出的长度
        return c;
    }
}
```