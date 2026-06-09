### 解题思路
此处撰写解题思路
本来以为自己写了一堆垃圾，结果还不错，哈哈

中间部分解释一下，以免以后忘了

sum有四种情况：(顺序调换不会影响)
48(0)	48(0)	0		96		//此时cf = 0；ans[j] = 0;
49(1)	48(0)	0		97		//此时cf = 0；ans[j] = 1;
49(1)	48(0)	1		98		//此时cf = 1；ans[j] = 0;
49(1)	49(1)	1		99		//此时cf = 1；ans[j] = 1;
这是算法的核心
最后别忘了如果算出的结果是以零结尾，则需要把最后以为去除
如 0 和 0 相加 此时ans的大小为2，如果不去除最后一位就会变成00
### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string a1 = a;
        string b1 = b;

        reverse(a1.begin(), a1.end());
        reverse(b1.begin(), b1.end());
        int cf = 0, size = a1.size() > b1.size() ? a1.size() + 1 : b1.size() + 1;
        unsigned int j = 0;
        string ans(size,'0');
        while (j < size) {
            char c1 = j < a1.size() ? a1[j]: '0';
            char c2 = j < b1.size() ? b1[j]: '0';
            int sum = c1 + c2 + cf;
            if (sum == 96) {
                cf = 0;
                ans[j] = '0';
            }
            else if (sum == 97) {
                cf = 0;
                ans[j] = '1';
            }
            else if (sum == 98) {
                cf = 1;
                ans[j] = '0';
            }
            else {
                cf = 1;
                ans [j] = '1';
            }
            j++;
        }
        if (ans[size - 1] == '0') {
            ans = ans.substr(0, ans.size() - 1);
        }
        reverse(ans.begin(), ans .end());
        return ans;
    }
};
```