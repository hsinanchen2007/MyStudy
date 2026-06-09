### 解题思路
可以直接把字符串分成有两部分组成：
1、“1”也就是竖直往下的那个字符串
2、“/”斜上放下的字符串，可以把他也看做“1”型的。只不过少了一个“头”和一个“尾”
由于由两部分组成，因此定义一个bool变量flag来判断现在需要处理哪一段。
每次处理之前都需要将column变量初始化为长度为numRows的空字符串。因此接下来只需要对有字符的位置进行赋值即可，其他情况无论是退出，还是处理“头”和“尾”都十分便捷。
在“1”型时，直接顺序将column变量赋值即可。
但是在“/”型时，需要从后往前赋值。
同时在处理完一段之后将结果存储到result中。
接下来就是通过result的结果，按照所需的顺序对output进行赋值即可。
顺序为先行后列，因为每一行中存贮的都是一段数据。而每一列中是顺序存储的结果。
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result;
        string temp(numRows, ' ');
        string column;
        string output;
        bool flag = true;//flip sign
        for (auto ptr = s.begin(); ptr != s.end(); ) {
            column = temp;
            if (flag) {
                for (int i = 0; i < numRows && ptr != s.end(); i++) {//from the top down
                         column[i] = *ptr;     
                         ptr++;              
                }//"1" type

            }
            else {
                for (int i = numRows - 2; i > 0 && ptr != s.end() ; i--) {// from bottom to 
                    column[i] = *ptr;     
                    ptr++;              
                }

            }"/"type
            flag = !flag;
            result.push_back(column);
        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < result.size(); j++) {
                if (result[j][i] != ' ') 
                    output.push_back(result[j][i]);
            }
        }
        return output;
    }
};
```