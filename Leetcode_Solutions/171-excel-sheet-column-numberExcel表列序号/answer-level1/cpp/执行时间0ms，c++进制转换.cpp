![image.png](https://pic.leetcode-cn.com/bb079aece4cff61cf78598bcbacbc830f8b6ddc9d7f3e876fc55b41bf08025df-image.png)

本题相当于168题的逆运算，是从26进制转换为10进制。注意此题26进制的范围是1到26，按照进制转换规则从左往右遍历字符串即可得到答案。
```
class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans *= 26;
            ans += s[i] - 'A' + 1;
        }
        return ans;
    }
};
```
