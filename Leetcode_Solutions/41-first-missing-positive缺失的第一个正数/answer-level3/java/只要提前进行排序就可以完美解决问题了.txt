### 解题思路

[0,1,1,2,2]
第一次提交的时候没注意，被这个重复的情况给绊住了。
于是添加while循环，将相同元素的内容直接跳过。

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int minRes = 1;
        for(int i=0; i<nums.length;i++){
            int val = nums[i];

            // 注意要去除相同元素的影响
            while(i+1<nums.length && nums[i+1] == nums[i]){
                i ++;
            }
            if (val > 0){
                if(minRes == nums[i]){
                    minRes ++;
                    continue;
                } else{
                    return minRes;
                }
            }
        }
        return minRes;
    }
}
```