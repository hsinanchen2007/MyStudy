### 解题思路
主要还是理解，每一次循环都是对上一次一次计数统计，那么我们定义一个变量count表示字符重复次数，以pre表示上一个字符的位置，当当前字符与上一个字符相等，则count++， 否则，则表示字符计数终止，便将count跟pre代表的字符写入答案字符串，pre等于当前字符位置，重新开始计数。完成循环后，再将最后一个字符情况写入答案字符串即可。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int count;
        for(int i = 1; i < n; i++){
            string temp = "";
            int pre = 0;
            count = 1;
            for(int j = 1; j < s.size(); j++){
                if (s[j] != s[pre]){
                    temp += (char)(count + 48);
                    temp += s[pre];
                    count = 0;
                    pre = j;
                }
                count ++;
            }
            
            temp += (char)(count + 48);
            temp += s[pre];
            s.clear();
            s = temp;
        }
        return s;
    }
};
```