### 解题思路
找到高位第一个6，将其变为9即可

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {

        vector<int> v;
       
        while(num)
        {
            v.push_back(num % 10);
            num /= 10;
        }

        for(int i = v.size() - 1; i >= 0; --i)
        {
            if(v.at(i) == 6)
            {
                v.at(i) = 9;
                break;
            }
        }
        
        for(int i = 0; i < v.size(); ++i)
        {
            num += v.at(i) * pow(10, i);
        }

        return num;
    }
};
```