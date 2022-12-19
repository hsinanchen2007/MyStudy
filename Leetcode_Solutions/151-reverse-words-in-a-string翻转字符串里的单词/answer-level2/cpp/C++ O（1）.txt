### 解题思路
先整体反转，再逐单词反转；并独立处理首尾、中间的冗余空格

### 代码

```cpp
/*
额外空间 O(1)
先整体反转，再逐单词反转；并独立处理首尾、中间的冗余空格
*/
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());                        //整体反转
        int start = 0, end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') start++;//首空格
        while (end >= 0 && s[end] == ' ') end--;            //尾空格
        if (start > end) return "";                         //特殊情况

        for (int r = start; r <= end;) {                    //逐单词反转
            while (s[r] == ' ' && r <= end) r++;            //单词的左空格
            int l = r;
            while (s[l] != ' ' && l <= end) l++;            //单词的右空格
            reverse(s.begin() + r, s.begin() + l);          //将空格间的单词反转
            r = l;
        }

        int tail = start;                                   //处理中间冗余空格
        for (int i = start; i <= end; i++) {
            if (s[i] == ' '&&s[i - 1] == ' ') continue;     //碰到两个连着的空格跳过本次循环
            s[tail++] = s[i];                               //否则改变(复制)字符串
        }
        return s.substr(start, tail - start);               //最终返回 从start开始 tail-start长度的最终字符串
    }
};
```
![image.png](https://pic.leetcode-cn.com/45ba97e7f79efcdf0f86a541cdb0a828e985fe782db9ddf95dadeb51426f3d77-image.png)
