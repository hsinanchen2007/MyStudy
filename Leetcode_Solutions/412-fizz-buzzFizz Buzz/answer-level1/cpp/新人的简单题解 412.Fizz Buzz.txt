### 解题思路
4ms 97.44%还不错
to_string函数用于将数字转化为字符串，方便好用

### 代码

```cpp
string Value(int n)
{
    if(n%3==0&&n%5==0) return "FizzBuzz";
    if(n%3==0&&n%5!=0) return "Fizz";
    if(n%3!=0&&n%5==0) return "Buzz";
    return to_string(n);
}


class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> res;
        for(int i=1;i<=n;i++)
        {
            res.push_back(Value(i));
        }
        return res;
    }
};
```