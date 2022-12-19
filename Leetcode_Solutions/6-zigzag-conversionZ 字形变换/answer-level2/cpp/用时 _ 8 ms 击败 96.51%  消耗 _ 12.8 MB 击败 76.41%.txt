### 解题思路
用N个桶收集每一行的数据，最后合并

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        int num = 2*(numRows-1);                //去掉首尾，一组为2*numRows-2个；
        int k;
        string *str = new string[numRows];      //创建numRows个string数组
        if(len == 1) return s;                  // 如果长度为1，num为0，0不能作为除数，需要单独处理
        for(int i = 0; i < len; i++){
            k = i % num;                        //以num个数为一组，只要考虑组内分配即可
            if(k < numRows) str[k].push_back(s[i]);
            else{
                k = k % numRows;                //分配组内大于行数的数据
                str[numRows - k - 2].push_back(s[i]);
            }
        }
        //收集分配的字符串
        for(int m = 1; m < numRows; m++){
            str[0] += str[m];
        }
        return str[0];
    }
};
```