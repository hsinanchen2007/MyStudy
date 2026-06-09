题目中的给定的输入是整数数组，里面的元素只有三种：负整数、正整数、以及0。
我们都知道：
a.0乘任何数都等于0。
b.而负整数或正整数乘任何一个非0整数I，结果的绝对值都会大于I。

根据a.假如我们选定的子序列中只要有元素是0，所得的结果都会是0。
根据b.不包含0的子序列，元素越多乘积的绝对值越大。
我们可以看作，0把数组截断了，这样的话，子序列就有这两种：
1）[0]
2）被0截断后，正整数和负整数组成的最长子序列
![image.png](https://pic.leetcode-cn.com/7eaf9a7f2fd3237f1787345cd2abe32b5fea85cb6eee7694bd5aeac34d1cf237-image.png)


毫无疑问，情况1）的乘积是0。
但情况2）的乘积却是有正有负的：
当2）的乘积是正数或者只有一个元素时，毫无疑问，此子序列的最大乘积就是它。
当2）的乘积是负数并且元素有2个以上时，设子序列的乘积是P，算出X = E1 * E2 * E3 * ... * En(En是子序列中第一个负整数)，
 Y = Em * Em+1 * ... * Ek (Em为子序列中最后一个负整数，k为子序列最后一个元素)
假如|X| < |Y|， 最大的乘积是P/X，反之是P/Y。

![image.png](https://pic.leetcode-cn.com/7f3564e0749c21e7bcdd194ad1d05e8b8a4658d797a92603defafa7adeb4011f-image.png)

实现的时候，其实我们并不需要计算Y的值，因为我们从左往右遍历的时候会顺便把P/Y的值计算出来（假如P是负数的话）。
```
 public int maxProduct(int[] nums) {
            int result = -2147483648;   //记录结果
            int product = 0;
            int negative = 0;   //上文中的X
            boolean negativeInit = false;   //用来标记，这段子序列中，是否包含负数
            for(int i = 0; i < nums.length; i ++) {
                if(product == 0) {  //遇到0就重新初始化
                    negativeInit = false;
                    product = 1;
                }
                product *= nums[i];
                if(product > result) {
                    result = product;
                }
                if (negativeInit && product / negative > result) {
                    result = product / negative;  //上文中的P/X
                }
                if(product < 0 && !negativeInit) {
                    negativeInit = true;
                    negative = product;
                }

            }
            return result;
        }
```
时间复杂度和空间复杂度均为O(n)。