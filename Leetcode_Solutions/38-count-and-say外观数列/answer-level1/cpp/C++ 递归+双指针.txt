### 解题思路
![image.png](https://pic.leetcode-cn.com/d51bd9e557c9465485db2e516161d0c4d9d6ed873efc6833b126d3085c1ff014-image.png)
思路并不难，就是找出某一个值被重复了几次，这一块儿需要一个双指针，而依次往下找需要一个递归。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n)
    {
        if(n == 1) return "1";
        string cur = "1";
        for(int i = 2; i <= n; i++)
        {
            cur = count(cur);
        }
        return cur;
    }

    string count(string str)
    {
        int i = 0,j = 0,num = 0;
        string s;
        while(j < str.length() )
        {
            if( str.at(j) == str.at(i) )
            {
                num++;
            }
            else
            {
                s.push_back(num + '0');
                s.push_back(str.at(j-1) );
                num = 1;
                i = j;
            }
            if( j + 1 == str.length() )
            {
                s.push_back(num + '0');
                s.push_back(str.at(j) );
            }
            j++;
        }
        return s;
    }
};
```