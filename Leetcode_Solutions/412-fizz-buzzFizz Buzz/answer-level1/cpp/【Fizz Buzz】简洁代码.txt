### 思路

### 代码

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            string tmp;
            if (i % 3 == 0) {
                tmp += "Fizz";
            }
            if (i % 5 == 0) {
                tmp += "Buzz";
            }
            if (tmp.empty()) {
                tmp = to_string(i);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```

### 另一种写法
```c++
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {            
            if (i % 15 == 0) {
                res.push_back("FizzBuzz");
            } else if (i % 5 == 0) {
                res.push_back("Buzz");
            } else if (i % 3 == 0) {
                res.push_back("Fizz");
            } else {
                res.push_back(to_string(i));
            }            
        }
        return res;
    }
};
```
