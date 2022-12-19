### 解题思路
过于简单

### 代码

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for(int i=1;i<n+1;i++)
        {
            string a = i%3==0?"Fizz":"";
            string b = i%5==0?"Buzz":"";
            string c = a+b;
            s.push_back(c+=c==""?to_string(i):"");
        }
        return s;
    }
};
```