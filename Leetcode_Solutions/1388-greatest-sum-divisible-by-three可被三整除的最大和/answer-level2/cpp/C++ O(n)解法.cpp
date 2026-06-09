思路：先遍历一次，求所有元素的和sum，这样就可以知道所有数的和模3后余多少。
1、如果是余0，那么直接返回sum就行了。
2、如果是余1，那么此时sum减去一个模3余1的最小的数；或是减去两个模3余2的最小的数。余数也会变为0。选择这两种情况sum的最大值。
3、如果是余2，那么此时sum减去一个模3余2的最小的数；或是减去两个模3余1的最小的数。余数也会变为0。选择这两种情况sum的最大值。

此外这题还可以用dp写，dp[i]代表 对3取模后余i的最大和。那么当我们遍历一个数num的时候，假设num%3=1，那么dp[2]+num就余0了，此时比较 dp[2]+num 和 dp[0]，两者的较大值赋值给dp[0]. 同理的，可以更新其他的dp[i]. 递推关系：dp[i] = max(dp[i], num + dp[(3+i-num%3)%3]);

```
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int maxx = 10005;
        int yuer1 = maxx, yuer2 = maxx, yuyi1 = maxx, yuyi2 = maxx;
        int sum = 0;
        for (auto n : nums) {
            int yu = n % 3;
            if (yu == 2) {
                if (n < yuer1) {
                    yuer2 = yuer1;
                    yuer1 = n;
                } else if (n < yuer2) {
                    yuer2 = n;
                }
            } else if (yu == 1) {
                if (n < yuyi1) {
                    yuyi2 = yuyi1;
                    yuyi1 = n;
                } else if (n < yuyi2) {
                    yuyi2 = n;
                }
            }
            sum += n;
        }
        int yu = sum % 3;
        if (yu == 0) {
            return sum;
        } else if (yu == 1) {
            if (yuer1 + yuer2 < yuyi1) {
                return sum - yuer1 - yuer2;
            } else if (yuer1 != maxx) {
                return sum - yuyi1;
            } else {
                return 0;
            }
        } else if (yu == 2) {
            if (yuyi1 + yuyi2 < yuer1) {
                return sum - yuyi1 - yuyi2;
            } else if (yuer1 != maxx) {
                return sum - yuer1;
            } else {
                return 0;
            }
        }
        return 0;
    }
};
```