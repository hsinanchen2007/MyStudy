### 解题思路
构造一个二维数组，然后逐个遍历字符串，第一列为numRows个元素，然后是z形的numRows-2个元素，这里记得行号是递减的；
构造好二维数组后逐行拼接成结果即可

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() < 1) return s;
        char A[numRows][s.length()];
        for(int i = 0; i< numRows; i++){
            for(int j = 0; j < s.length(); j++){
                A[i][j] = '*';
            }
        }
        int posRow = 0; 
        int posCol = 0;
        int i = 0;
        while(i < s.length()){
            for(int row = 0; row < numRows && i < s.length(); row++){
                A[row][posCol] = s[i];
                i++;
            }
            posCol += 1;
            posRow = numRows -2;
            for(int col = 0 ; col < numRows-2 && i < s.length();col++){
                A[posRow--][posCol] = s[i];
                i++;
                posCol+=1;
            }
        }
        string ret;
        for(int i = 0; i< numRows; i++){
            for(int j = 0; j < s.length(); j++){
                if(A[i][j] != '*'){
                    ret.push_back(A[i][j]);
                }
            }
        }
        return ret;
    }
};
```