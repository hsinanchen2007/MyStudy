### 解题思路
    最大子序列和：在循环中判断前面元素和是否小于0，小于0则候选子序列从当前元素开始。
    最大子序列积：在循环中判断当前元素是否小于0， 小于0则将 当前元素*以前一个元素结尾的最小的子序列积 = 以当前元素结尾的最大的子序列乘积imax； 同时更新 以当前元素结尾的最小的子序列乘积iMin = 当前元素*以前一个元素结尾的最小的子序列积。  最后更新最大的子序列乘积 max = Math.max(max, iMax)。
### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        //最大的子序列乘积
        int max = Integer.MIN_VALUE;
        //以当前元素结尾的，最大的，子序列乘积
        int iMax = 1;
        //以当前元素结尾的，最小的，子序列乘积
        int iMin = 1;

        for (int i : nums){
            if (i < 0){
                int tmp = iMax;
                iMax = iMin;
                iMin = tmp;
            }

            iMax = Math.max(iMax* i, i);
            iMin = Math.min(iMin* i, i);
            max = Math.max(max, iMax);
        }

        return max;
    }
}
```