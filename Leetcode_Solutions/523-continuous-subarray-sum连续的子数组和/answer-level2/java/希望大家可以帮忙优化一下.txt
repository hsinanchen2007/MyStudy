### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        //用于记录当前位置
        int i = 0;
        while(i < nums.length){
            //用于记录连续数的总和
            int num = 0;
            for(int j = i;j < nums.length;j++){
                num += nums[j];
                //根据题目要求，至少要两个数，除数为零做特殊处理
                if(j-i>0 && num == k){
                    return true;
                }else if(j-i>0 && k!=0 && num % k == 0){
                    return true;
                }
            }
            i++;
        }
        return false;
    }
}
```