### 解题思路
解决问题方法还是遍历和存储字符串的问题
顺序遍历s, vectort<string> conv (看成二维动态字符数组)保存结果
conv 采用 N (即到 Z 型) 遍历存储 s的字符
1.即从上往下遍历conv, conv[i++] += s[k++]
2.当conv == numRows时，把 i = numRows - 2;
  再conv[i--] += s[k++](while i >=0 )时
3 重复以上过程即可
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        //定义动态字符串数组
      vector<string> conv(min(numRows, int(s.size()))); // 防止s的长度小于行数
        int i = 0, j = 0, k = 0;
        //遍历示意图如下，倒Z型
        //  |     |
        //  |   | |
        //  | |   |
        //  |     |
        while(k < s.size())
        {
            // i++， j不变，即往下遍历
            while(i < numRows && k < s.size())
            {
                conv[i++] += s[k++];
            }
            // 重置 i = numRows - 2;
            // 往右上遍历
            i = numRows - 2;
            while(i >= 0 && k < s.size())
            {
                conv[i--] += s[k++];
            }
            //重置 i = 1, 再往下遍历
            i = 1;
        }
        string ans("");
        for(i = 0; i < conv.size(); i++)
            ans += conv[i];
        return ans;
    }
};
```