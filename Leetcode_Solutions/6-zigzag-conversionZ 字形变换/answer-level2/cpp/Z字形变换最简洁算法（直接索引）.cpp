### 解题思路
算法：
1.当s的长度小于numRows==1时，直接返回s
2.当numRows>1:
设立空字符串new_s
设字符串长度为len
将每一列和每一列后的斜对角线看成一整列col，那么每列包含的字符数为numRows+numRows-2=2*numRows -2.
列的数量cols = len/(2*numRows -2)
对于第i行第j列，分两种情况：
（1）当i==0 || i==numRows-1
此时j列只有一个元素，其在s中的索引为j*(2*numRows - 2)+i
如果j*(2*numRows - 2)+i<len,new_s+=s[j*(2*numRows - 2)+i]
(2)当i>0 && i<numRows-1
此时j列有两个元素，对应索引为j*(2*numRows - 2)+i和(j+1)*(2*numRows - 2) - i
判断这两个索引是否超出字符串，未超出则添加到new_s

复杂度分析
时间复杂度循环次数为numRows*len/(2*(numRows-1))~~n/2,时间复杂度O(n)
空间复杂度O(1)
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        string new_s;
        int len = s.length();
        if(len<=numRows || numRows == 1) return s;
        
        int cols = len/(2*numRows - 2);
        
        for(int i=0; i<numRows; ++i){
            for(int j=0; j<cols+1; ++j){
                if(j*(2*numRows - 2)+i<len) new_s += s[j*(2*numRows - 2)+i];
                if(i>0 && i<numRows-1 && (j+1)*(2*numRows - 2) - i < len)
                    new_s += s[(j+1)*(2*numRows - 2) - i];
            }
        }

        return new_s;
    }
};
```