### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if(nums.length==0)
        return 0;
        int count=0,min=Integer.MAX_VALUE,len=0;
        for(int i=0;i<nums.length;i++){
            len=0;count=0;
            for(int j=i;j<nums.length;j++){
                count+=nums[j];
                len++;
                if(count>=s&&len<min){
                    min=len;
                    break;
                }
            }
        }
        if(min==Integer.MAX_VALUE)
        return 0;
        return min;
    }
}
```