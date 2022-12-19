### 解题思路
这道题的题目有点坑啊，不是Z字型，明明是N字型。想了好久解不出来
字符串排列如下面所示：
0    6     12
1  5 7  11 13
2 4  8 10  14
3    9     15
看了题解发现两种思路
1.通过数学的方法。计算出每一行元素位置的表达式
··i==0||i==numRows-1时 res += s[i+j]; ,注意要确保i+j<s.size()
··其他情况下，在circle之间都会插入一个值res += s[j+circle-i];，注意确保j+circle-i<s.size()


2.创建数组，通过floor控制字符为第几行的。这个方法很巧妙，但时执行用时和内存消耗都很高。


执行用时 :4 ms, 在所有 C++ 提交中击败了99.62% 的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int circle = numRows*2 - 2;
        string res;
        for(int i = 0;i<numRows;++i){
            for(int j = 0;i+j<s.size(); j+=circle){
                res += s[i+j];
                if(i!=0&&i!=numRows-1&&j+circle-i<s.size()){
                    res += s[j+circle-i];
                }
            }
        }
        return res;
    }
    // 执行用时 :4 ms, 在所有 C++ 提交中击败了99.62% 的用户
    // 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户


    string convert(string s, int numRows) {
        if(1==numRows) return s;
        vector<string> temp(min(int(s.size()), numRows));
        int floor = 0;
        bool reverse = false;
        for(char c:s){
            temp[floor] += c;
            if(floor==0||floor==numRows-1){
                reverse = !reverse;
            }
            floor += reverse ? 1 : -1;
        }
        string res;
        for(string row : temp){
            res += row;
        }
        return res;

    // 执行用时 :28 ms, 在所有 C++ 提交中击败了27.10% 的用户
    // 内存消耗 :12.1 MB, 在所有 C++ 提交中击败了62.40%的用户

    }
};
```