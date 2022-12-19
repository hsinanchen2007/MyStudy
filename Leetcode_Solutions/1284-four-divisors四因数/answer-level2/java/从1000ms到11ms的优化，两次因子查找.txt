原先比赛的时候写了个比较暴力的解法，后来优化了下，跑完后结果我也是意外了下，没想到会这么快
![image.png](https://pic.leetcode-cn.com/30f50ec0ac84f591e6be6269d31d6de8a9809eb8b807eaffea8cae93d7e1d62d-image.png)

说说优化点吧
1. 开方，跑到开方的位置就能够判断所有的因子了
2. 遇到相乘等于num的两个因子值相同的情况，立刻就可以判断出不是4个因子，因为这种情况因子数必然是奇数个
3. 从2开始找，**遇到第一个因子就退出循环**，记录两个因子a和b，进入下一步判断。这里有一个关键的信息，**a必然是除1以外最小的因子且是质数，b必然是除自身以外最大的因子**。这时候**只要再判断b是否有非a,非b的因子**，这时候的b已经比num的量级少了一大块了，已经算是优化了。
4. 利用a是num的除1外最小因子，可以得出b的除1外最小因子大于等于a，所以找b的因子的时候，就可以从a开始找（这里需要注意的是：a * a = b这种情况需要排除，所以只要判断b的因子较大的那个不是a即可


接下来贴代码吧

```java
class Solution {
    public int sumFourDivisors(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += divisors(num);
        }
        return sum;
    }
    
    private int divisors(int num) {
        int a = -1;
        int b = -1;
        int last = (int) Math.sqrt(num);
        for (int i = 2; i <= last; i++) {
            if (num % i == 0) {
                a = i;
                b = num / i;
                if (a == b) { // 有平方根的数，因子数必然是奇数个
                    return 0;
                }
                break;
            }
        }
        if (a == -1) {
            return 0;
        }

        // a必然是素数，因为a是num除1外的最小因子，b是num除自身外最大的因子
        // 综上，只需判断b是否有非a的因子
        // b的非1因子必然大于等于a的
        last = (int) Math.sqrt(b);
        for (int i = a; i <= last; i++) {
            if (b % i == 0 && (b / i) != a) {
                // 有第5个因子，i不可能等于b，所以不用判断i == b
                // b / i 是大于等于 i 的，这里有种特殊情况 i == b/i == a，通过后一项判断排除
                return 0;
            }
        }

        return a + b + 1 + num;
    }
}
```