### 解题思路

- 前话 ：题目限制数组长度为 $5$ ，数组的数取值为 $[0, 13]$，如果不限制数组长度，那顺子长度必定$>=5$，可以做个特判，下面是解析：
   - 先对数组排序，再去计算当前数和前面一个数的$diff$（间隔），就是我们还需要多少张牌填进来，如果是顺子，比如 $1、2、3$，那么最后计算下来的总的 $diff$ 为 $0$，也就是不需要牌再填进来，如果不是顺子，比如 $0、0、1、2、5$,那就需要两张牌填进来
   - 顺子中肯定不能有重复的非零数字
   - 如果 $diff$ 不为0，就要看 $0$ 的个数了，$diff-zero == 0$ 即可

- 然后我就那么提交了，提交时候发现错误，有个三个大王用例
![image.png](https://pic.leetcode-cn.com/c3bb7e994b7ca6d9805cc81f2f4e6a1b7c93cc969dbefdfff1e79dc48dd8cc6f-image.png)

再分析一下，实际上只要改成 $diff-zero <= 0$，因为多出来的 $0$ 我们不用管它

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        Arrays.sort(nums);
        int diff = 0;
        int zero = 0;
        int flag = -1;   //用于判断是否为第一个
        for (int i = 0; i < nums.length; i++) {
            //如果是0，统计 跳过
            if (nums[i] == 0) {
                zero++;
                continue;
            }
            //如果是第一个，跳过
            if (flag == -1) {
                flag = nums[i];
                continue;
            }
            //如果有重复的，return false
            if (nums[i] == nums[i - 1]) {
                return false;
            }
            diff += nums[i] - nums[i - 1] - 1;
        }
        return diff == 0 || (diff - zero <= 0);
    }
}
```