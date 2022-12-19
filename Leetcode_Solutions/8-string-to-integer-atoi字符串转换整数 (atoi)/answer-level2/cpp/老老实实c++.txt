### 解题思路
此处撰写解题思路

### 代码

```cpp
#define INT_MAX 0x7fffffff
#define INT_MIN (-INT_MAX-1)

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        long long tmp = 0;
        int len = str.size();
        int first = 0;
        int usechar[1024] = {0};
        int count = 0;
        bool isdigit = false;
        for (int i = 0; i < len; i++) {
            if (str[i] == ' ' && isdigit == false) {
                continue;
            }
            if (str[i] == '-' && first == 0 && isdigit == false) {
                isdigit = true;
                first = 1;
                continue;
            }
            if (str[i] == '+' && first == 0 && isdigit == false) {
                isdigit = true;
                first = 2;
                continue;
            }
            if (str[i] >= '0' && str[i] <= '9') {
                isdigit = true;
                usechar[count++] = str[i];
            }
            else
            {
                break;
            }
        }
        int i = 0;
        if (first == 0 && isdigit == true) {
            while (i < count) {
                tmp = tmp * 10 + usechar[i] - '0';
                if (tmp > INT_MAX) {
                    tmp = INT_MAX;
                    break;
                }
                    
                i++;        
            }
        }
        else if (first == 1 && isdigit == true){
            while (i < count) {
                tmp = tmp * 10 + usechar[i] - '0';
                if (-tmp < INT_MIN) {
                    tmp = INT_MIN;
                    break;
                }
                i++;       
            }
            tmp = -tmp;
        }
        else if(first == 2 && isdigit == true) {
            while (i < count) {
                tmp = tmp * 10 + usechar[i] - '0';
                if (tmp > INT_MAX) {
                    tmp = INT_MAX;
                    break;
                }
                    
                i++;        
            }
        }
        return (int)tmp;
    }
};
```