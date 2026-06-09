### 方法一 暴力
```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) ans.emplace_back("FizzBuzz");
            else if (i % 3 == 0) ans.emplace_back("Fizz");
            else if (i % 5 == 0) ans.emplace_back("Buzz");
            else ans.emplace_back(to_string(i));
        }
        return ans;
    }
};
```

### 方法二 散列表（解决更复杂的规则）
```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        map<int, string> fizzDict;
        fizzDict[3] = "Fizz";
        fizzDict[5] = "Buzz";

        for (int i = 1; i <= n; ++i) {
            string tmp = "";
            for (auto f : fizzDict) if (i % f.first == 0) tmp += f.second;
            if (tmp.empty()) tmp = to_string(i);
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
```