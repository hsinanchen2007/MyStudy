### 解题思路
1.目标:
    生成一个string数组，记录每一行应该显示的字符串，最后拼接起来即可。
2.数组大小:
    为s的长度 和 行数的较小值。
3.填充数组:
    从前往后遍历字符串s, 它的每个字符的pos都有一个行号line, line-1 即是数组的索引。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        //cout<<"be here 1"<<endl;
        int len_s = s.size();
        //cout<<"be here 2"<<endl;
        int str_arr = len_s<numRows?len_s:numRows;
        if(str_arr<=1)return s;
        string ret[str_arr];
        //cout<<"be here 3"<<endl;
        int pos = 0;
        int circle = 2*numRows - 2;
        int idx;
        int line;
        //cout<<"len_s: "<<len_s<<", num: "<<numRows<<endl;
        while(pos<len_s){
            idx = (pos+1)%circle;
            idx = idx==0?circle:idx;
            line = idx<=numRows?idx:numRows-(idx-numRows);
            //cout<<"idx: "<<idx<<", line: "<<line<<", pos: "<<pos<<endl;
            ret[line-1]+=s[pos++];
        }
        for(int i = 1;i<str_arr;i++){
            ret[0]+=ret[i];
        }
        return ret[0];
    }
};
```