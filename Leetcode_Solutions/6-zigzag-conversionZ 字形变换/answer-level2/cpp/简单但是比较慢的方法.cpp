### 解题思路
按照给的numRows建立一个二维vector
遍历s，把对应的字符放到应该在的行中去，也就是把它push进对应行的vector。
在遍历输出
注意特殊情况
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<vector<char>> output;
        for(int i=0;i<numRows;i++)
        {
            vector<char> mid;
            output.push_back(mid);
        }
        int i=0;
        int col=0;
        int row=0;
        while(i<s.length())
        {
            if(row==0)
            {
                int count=numRows;
                while(count--&&i<s.length())
                    output[row++].push_back(s[i++]);
                row-=2;
            }
            else
                output[row--].push_back(s[i++]);
        }
        string mid;
        for(int i=0;i<numRows;i++)
            for(int j=0;j<output[i].size();j++)
                mid+=output[i][j];
        return mid;
    }
};
```