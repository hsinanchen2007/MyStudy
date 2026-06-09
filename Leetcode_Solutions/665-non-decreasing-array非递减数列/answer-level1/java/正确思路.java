### 解题思路
给出的原始测试用例： 4,2,3 数学思路是： 看到4大于2 所以我们变更4到满足非递减的值2，然后记一次数完成。
那么我们也就很容易写出来if nums[i]>nums[i+1] count++ nums[i]=nums[i+1] 这样的代码

随后报错 给出测试用例 3,4,2,3 数学思路： 看到4大于2 如果我们像刚才一样4改成2，前面本来满足的3,4变成了3,2就不满足了 所以在考虑问题的时候 必须要把3,4,2打包在一起考虑 这时你发现，把2改成4 就既保证了前面非递减性没变，又保证了局部这三个的非递减性 所以可得if nums[i+1]<nums[i-1] nums[i+1] = nums[i] 接着考虑下数组越界，以及return 条件即可得到最终结果。

另外你可能会发现 长度为1，2的数组必定满足要求。 

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
       int count = 0;
        if (nums.length < 3) {
            return true;
        }
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
                if (i > 0 && nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i + 1];
                }
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
}
```