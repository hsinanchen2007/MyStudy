先对长度为5的数组排序，定义一个布尔值hasGap表示该数组相邻位置的数字间是否有空缺需要0来填补。接着遍历该数组，确定0的个数和有空缺需要填补的0的个数。

代码如下：

```java
class Solution {
    public boolean isStraight(int[] nums) {
        Arrays.sort(nums);
        // count定义0的个数
        int count = 0;
        // hasGap表示相邻位置的数字是否相差1，不满足则为false
        boolean hasGap = false;
        // needZero表示需要用来填补空缺的0的个数
        int needZero = 0;
        // 遍历
        for (int i = 0; i < 4; i++){
            if(nums[i]==0){
                count++;
                continue;
            }
            // 相邻位置的数字间有空缺
            if(nums[i]+1!=nums[i+1]){
                // 相邻位置的数字相同，直接返回false
                if(nums[i]==nums[i+1]) return false;
                // 表明相邻位置的数字间有空缺
                hasGap = true;
                // 更新需要填补空缺的0的个数
                needZero += nums[i+1]-nums[i]-1;
            }
        }
        // 数组相邻位置数字间没有空缺
        // 注意，这里是<=，不是==，防止[0,0,0,9,11]的情形出现
        else if (needZero <= count) return true;
        else return false;
    }
}
```
