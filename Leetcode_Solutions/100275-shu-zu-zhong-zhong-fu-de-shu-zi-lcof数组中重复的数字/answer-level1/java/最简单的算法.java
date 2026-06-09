### 解题思路
此处撰写解题思路
1.审题；题意：将数组中重复的数字返回；只需要返回一个数字即可
2.算法：就是遍历数组：第一次遍历第一个数字；第二次遍历第一次遍历的下一个数；最后判断他们两个值是否相等即可
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i=0;i<nums.length-1;i++){//第一次遍历
            for(int j=i+1;j<nums.length;j++){//第二次遍历
                if(nums[i]==nums[j]){
                    return nums[i];
                }
               
            }
            
        } return -1;
    }
}
```