举例 n = 3, k = 3
首先看第一位，按照全排列的规则，第一位数字按顺序是1, 2, 3，即
1xx
1xx
2xx
2xx
3xx
3xx
这里以每一位数开头的排列是有(n-1)!个。同理往后推。
那么在找第k个全排列，只要按位分块查找就可以得到结果，代码如下：

```
class Solution {
public:
    string getPermutation(int n, int k) {
        // n个数字有n!种排列
        // 按数字位数逐个计算
        string res = "";
        string temp = "";
        for (int i = 1; i <= n; i++) {
            temp += '0'+(char)i;
        }
        int f = factorial(n-1);
        int i = n-1;
        k--;
        while (res.size() < n) {
            int c = k/f;
            k %= f;
            res += temp[c];
            temp.erase(c, 1);
            f = (i == 0 ? 1 : f/i);
            i--;
        }
        return res;
    }
    
    int factorial(int n) {
        int res = 1;
        while (n > 0) {
            res *= n;
            n--;
        }
        return res;
    }
};
```
![60.第k个排列.PNG](https://pic.leetcode-cn.com/3f210be244106f3865d55a92434db063c3cab67823d41fc18fbb1b99030e785f-60.%E7%AC%ACk%E4%B8%AA%E6%8E%92%E5%88%97.PNG)
