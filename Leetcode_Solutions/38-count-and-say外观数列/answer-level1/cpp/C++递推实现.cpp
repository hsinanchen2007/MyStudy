c++递推实现，欢迎大家指正：
```
/*
    FT：字符串操作
    时间复杂度：O(n*2^n)，空间复杂度：O(2^n)
    最坏情况，pre字符串中字符两两不同，因此cur字符串的长度将会是pre字符串的两倍
    所以n-1次遍历中，pre字符串的扫描次数将是1+2+...+2^(n-1)=2^n-1，所以时间复杂度为指数形式
    最终生成的字符串最长是2^n，因此空间复杂度也为指数形式
*/

class Solution {
public:
    string countAndSay(int n) {
        string pre="1"; // n=1的外观数列
        for(int i=0;i<n-1;i++){ // 计算n-1次，计算后面的外观数列
            string cur="";
            char c=pre[0]; // 字符
            int t=1;    // 字符频数
            for(int j=1;j<=pre.size();j++){ // 计算cur
                if(j==pre.size() || pre[j]!=pre[j-1]){ // 注意j扫描结束后，要把最后的c和t加入到外观数列
                    cur+=char(t+'0');
                    cur+=c;
                    c=pre[j]; // 更新字符和频数
                    t=1;
                }
                else{
                    t++; // 频数累加
                }
            }

            pre=cur; // 更新pre
        }

        return pre; // 注意这里不能return cur，因为cur作用域有限
    }
};
```
