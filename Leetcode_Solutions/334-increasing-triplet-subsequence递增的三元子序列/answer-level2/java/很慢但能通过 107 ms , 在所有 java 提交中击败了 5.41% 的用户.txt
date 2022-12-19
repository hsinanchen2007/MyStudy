### 解题思路
最外层循环i，nums[i]用temp1表示
中层循环j,发现大于temp1开始第三层循环，nums[j]表示为temp2
内层循环k,发现大于temp2返回true；没找到那j继续循环，这个值一定比之前的temp2小，把temp2替换成这个小的
总能找到，否则返回false

### 代码

```java
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int len=nums.length,index,temp1,temp2;
        for(int i=0;i<len-2;i++){
            temp1=nums[i];
            for(int j=i+1;j<len-1;j++){
                if(nums[j]>temp1){
                    temp2=nums[j];
                    for(int k=j+1;k<len;k++){
                        if(nums[k]>temp2){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}
```