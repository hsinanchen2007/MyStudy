### 解题思路
遍历[1,n]内的所有整数，在[1,5]之内直接把结果push_back进容器里，在[n,6]之内只需遵循题目给出的条件进行判断得出结果就行了。
注意要先判断i是否既是3的倍数也是5的倍数。

### 代码

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> v;
        
        for(int i=1;i<=n;i++)
        {
            if(i==1 || i==2)
            {
                v.push_back(to_string(i));
            }
            else if(i==3)
            {
                v.push_back("Fizz");
            }
            else if(i==4)
            {
                v.push_back("4");
            }
            else if(i%3==0 && i%5==0)
            {
                v.push_back("FizzBuzz");
            }
            else if(i%3==0)
            {
                v.push_back("Fizz");
            }
            else if(i%5==0)
            {
                v.push_back("Buzz");
            }
            else
            {
                v.push_back(to_string(i));
            }
        }
        
        return v;

    }
};
```