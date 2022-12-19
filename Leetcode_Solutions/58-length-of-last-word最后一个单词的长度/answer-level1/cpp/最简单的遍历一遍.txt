### 解题思路
##解题思路 从末位开始从前遍历，如果遇到空格并且单词的长度num==0，则继续往前遍历，如果遇到单词，开始记录单词的长度，若再次遇到空格此时单词的长度num！=0，则遍历结束

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int num=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(num==0&&s.at(i)==' ')
                continue;
            else if(s.at(i)!=' ')
                num++;
            else if(num!=0&&s.at(i)==' ')
                break;
        }
        return num;
    }
};
```