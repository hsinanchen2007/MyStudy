### 解题思路
贪心思想：
每次跳跃之前，遍历能跳到的位置，确定覆盖范围最大的那个位置；
移动到那个位置，循环计算；
这样每次跳跃都能找到最远位置。

线性时间，其实只遍历了一遍数组。

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        
        int len = nums.length, cnt = 0, t = 0;
        if(len == 1) return cnt;

        for(int i = 0; i < len; i = t){

            int max = nums[i]+i;
            if(max >= len-1) return ++cnt;
            ++cnt;

            for(int j = i+1; j <= i+nums[i] && j < len; j++){
                if(nums[j]+j > max){
                    t = j;
                    max = nums[j]+j;
                }
            }

            if(nums[t] + t >= len-1) return ++cnt;
        }
        return cnt;
    }
}
```