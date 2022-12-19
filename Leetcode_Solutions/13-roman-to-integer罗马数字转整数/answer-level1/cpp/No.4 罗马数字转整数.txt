### 解题思路
1. 首先明确“罗马数字转整数”的规律：从左向右遍历每个字母，如果左边的字母大于右边的字母，则两数相加；如果两数相等，则两数相加；如果左边的字母小于右边的字母，则两数相减。
2. 首先创建一个容器（类似python里面的字典），unordered_map:按值索引,将字符与数值的一一对应关系表示出来；
3. 其次，遍历字符串，判断左右两边的字符对应的数值的关系，计算数值
4. 注意遍历至最后一个字符时，m[s[i+1]] 溢出，若以要加上 i== s.size()-1 这一条件，且在“||"关系中，如果前者为真，后者是不会被执行的。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L',50}, 
                                     {'C',100}, {'D', 500}, {'M', 1000}};
        for(int i=0;i<s.size();i++)
        {
            int val = m[s[i]];
            if ((i == s.size()-1)|| m[s[i]] >= m[s[i+1]])
                res += val;
            else
                res -= val;
        }
        return res;

    }
};
```