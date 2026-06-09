### 解题思路
1. 题目要求通过分割得到的最大数量，即尽可能多的分割。
2. 定义一个变量`balance`，当`balance`为`0`时达到平衡
3. 从左往右扫描字符串`s`，遇到`L`,`balance - 1`，遇到`R`，`balance + 1`
4. 当`balance`为`0`时即，更新记录`cnt ++`
5. 如果最后`cnt==0`，说明`s`只需要保持原样，返回`1`

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0;
        int balance = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L') balance --;
            if(s[i] == 'R') balance ++;
            if(balance == 0) cnt ++;
        }
        if(cnt == 0) return 1;
        else return cnt;
    }
};
```