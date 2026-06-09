### 分析
刚开始觉得是直接搜索，但是O(n^2)效率不行，后来参考别人学到了用动归。
已知前部分最优解，如果前部分最优解<=0表示其对当前位置数字没有任何增益，
所以前面最优解不与当前位置数字相加，然后在前面最优解与当前位置数字取最大那一个作为当前最优解

这个当前最优解又是下一个阶段的已知前部分最优解，依次递推，初始状态第一个数字肯定是当前最优解。

当然如果前面最优解>0肯定对于当前位置数字有增益，二者相加就行了。

还是要向各位大佬多多学习

### 代码
```java
class Solution {
    public int maxSubArray(int[] nums) {
        int res = nums[0];
        int sum = 0;
        for(int num : nums){
            if(sum > 0){
                sum+=num;
            }
            else sum = num;
            res = Math.max(sum,res);
        }
        return res;
    }
}
```