### 解题思路
1.string矩阵
自己写的方法不是很好，但是也是for循环反复迭代，迭代时采用数学规律
维护了一个string矩阵，通过摄者string的值来实现Z字形遍历，这种方法不是很好

2.直接遍历法




string矩阵
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {

        if(s.empty() || numRows< 1){
            return string("");
        }

        if(numRows == 1){
            return s;
        }

        string result;
        int k = numRows*2-2;
        int row = 0;
        int col = 0;
        vector<string> strvec = vector<string>(numRows,string((s.size()/k+1)*(numRows-1),' '));
        stringstream strstream;

        

        for(int i = 0;i<s.size();i++){
            if(i%k == 0){
                row= 0;
                col = i/k*(numRows-1);
            }else if(i%k < numRows){
                row++;

            }else if(i%k < k){
                row--;
                col++;
            }

            strvec[row][col] = s[i];

        }

        for(auto str:strvec){
            for(int j = 0;j<str.size();j++){
                if(str[j] != ' '){
                   strstream<< str[j];
                }
            }
        }
        strstream>>result;

        return result;



    }
};
```

直接遍历法
```

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};


```
