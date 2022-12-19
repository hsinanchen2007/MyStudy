### 解题思路
只需要实现二进制加法和右移模拟代码即可。

### 代码

```cpp
class Solution {
public:
    int numSteps(string s) {
        list<int> num;
        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; i--)
            num.push_back(s[i] - '0');
        while (num.size() > 1 || isZero(num)) {
            if (!isZero(num) && isEven(num)) {
                num.pop_front();
            } else {
                bool pos = false;
                list<int>::iterator it = num.begin();
                *(it) += 1;
                if (*(it) > 1) pos = true; 
                it++;
                for (; it != num.end(); it++) {
                    if (pos) {
                        *(it) += 1;
                    }
                    if (*(it) > 1) {
                        *(it) = 0;
                        pos = true;
                    } else {
                        pos = false;
                    }
                }
                if (pos)
                    num.push_back(1);
            }
            cnt++;
        }
        return cnt;
    }
    
    bool isEven (list<int> num) {
        list<int>::iterator it = num.begin();
        return *it != 1;
    }

    bool isZero (list<int> num) {
        list<int>::iterator it = num.begin();
        return num.size() == 1 && (*it == 0);
    }
};
```