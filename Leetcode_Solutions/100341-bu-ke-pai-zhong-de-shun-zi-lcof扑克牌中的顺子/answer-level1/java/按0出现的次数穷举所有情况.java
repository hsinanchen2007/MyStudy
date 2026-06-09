### 解题思路
先排序，按0出现的次数穷举所有情况

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        Arrays.sort(nums);
        int i=0;
        //找到排序后第一个非0元素的下标
        while(i<5&&nums[i]==0)
            i++;
        //判断是否有相同的非0元素
        for(int j=i;j<4;j++){
            if(nums[j]==nums[j+1])
                return false;
        }
        
        if(i>=4)
            return true;
        if(i==3&&nums[4]-nums[3]<=4)
            return true;
        if(i==2&&nums[4]-nums[2]<=4)
            return true;
        if(i==1&&nums[4]-nums[1]<=4)
            return true;
        if(i==0&&nums[4]-nums[0]<=4)
            return true;
        return false;
    }
}
```