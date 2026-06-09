### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int flag = 0; // 符号
        bool isStillEmpty = true; // 是否开头的空格仍在延续
        long int num = 0;
        long int cur = 0;
        for(int i=0;i<str.size();i++) {
            char c = str[i];
            if(c==' ') {
                if (isStillEmpty) continue;
                else return cur;
            }
            else if (c=='+'||c=='-') {
                isStillEmpty = false;
                if (flag!=0||num!=0) return cur;
                else {
                    if (c=='+') flag = 1;
                    else flag = -1;
                }
            }
            else if (c>='0'&&c<='9') {
                // 计算目前的数字
                isStillEmpty = false;
                if(flag==0) flag=1;
                int digit = c-'0';
                num = num*10+digit;
                cur = flag * num;
                // 是否溢出
                if (cur>=INT_MAX) return INT_MAX;
                else if (cur<=INT_MIN) return INT_MIN;
            } else {
                // 遇到字母
                return cur;
            }
        }
        return cur;
    }
};
```