### 解题思路
长度为N的无序数组在保证“无重复，无越界”的情况下，最多能装下N以内的正整数。

**借用数组的[0, n-1]存储区间，试图有序的摆放[1, N]区间的正整数：**
nums[i] 存储正整数 i + 1

如果出现重复，越界的情况，说明无效数字多占了一个坑位，丢掉无效数字的同时坑位减一。


![微信截图_20200303195218.png](https://pic.leetcode-cn.com/87f3ac05d286c83323a5e09699fdb079e0ce36ed828835c62eab4375c14d0389-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200303195218.png)

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int res = 0;
        int n = nums.length - 1;
        int tmp = 0;

        while(res <= n){
            if(nums[res] == res + 1){
                res++;
            }else{
                tmp = nums[res];
                if(tmp > n + 1 || tmp < res + 1 || nums[tmp - 1] == tmp){
                    nums[res] = nums[n--];
                }else{
                    nums[res] = nums[tmp - 1];
                    nums[tmp - 1] = tmp;
                }
            }
        }

        return res + 1;
    }
}
```