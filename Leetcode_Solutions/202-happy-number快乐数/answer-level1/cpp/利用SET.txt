### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    int op(int n) {
        int res = 0;
        while(n) {
            int t = n%10;
            res += t*t;
            n /= 10;
        }
        return res;
    }
public:

    bool isHappy(int n) {
        unordered_set<int> record;
        while (n != 1) {
            n = op(n);
            if (record.find(n) == record.end()) {
                record.insert(n);
            } else {
                return false;
            }

        }
        return true;
    }
};
```