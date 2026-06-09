### 解题思路
to_string函数

### 代码

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for(int i=1;i<=n;i++){
            if(i%5==0&&i%3==0){
                s.push_back("FizzBuzz");
            }else if(i%5==0){
                s.push_back("Buzz");
            }else if(i%3==0){
                s.push_back("Fizz");
            }else{
                s.push_back(to_string(i));
            }
        }
        return s;
    }
};
```