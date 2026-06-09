### 解题思路
- 若numsRow = 1, 则直接返回原串
- 按Z形, 对于Z形结果的每一行的字母的确定，分为以下两种情况
- 对于第一行和最后一行，每一步的步长都是step = (numRows - 1) * 2
- 对于i行(从0行开始编号)，第一步的步长是step1 = step - (i*2) , 第二步步长为 i * 2，第三步步长为step-(i * 2), 依次类推
- 用时12ms，内存8MB

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;  // 若numRows = 1，返回原串
        string ans = "";
        for(int i = 0; i < numRows; i++) {
            int step = (numRows - 1) << 1;  // 基本步长
            if(i == 0 || i == (numRows - 1)) {
                // 对于第一行和最后一行，第一个字母是s[i]，第二个字母是s[i+step]
                int cur_pos = i;
                while(cur_pos < s.length()) {
                    ans += s[cur_pos];
                    cur_pos += step;
                }
            }
            else {
                // 对于非首尾行，第一个字母是s[i]，第二个字母是s[i + (step - i*2)], 第三个字母是s[i + step]
                bool flag = true;
                int cur_pos = i;
                while(cur_pos < s.length()) {
                    ans += s[cur_pos];
                    cur_pos += (flag ? (step - (i << 1)) : (i << 1));
                    flag = !flag;
                }
            }
        }
        return ans;
    }
};
```