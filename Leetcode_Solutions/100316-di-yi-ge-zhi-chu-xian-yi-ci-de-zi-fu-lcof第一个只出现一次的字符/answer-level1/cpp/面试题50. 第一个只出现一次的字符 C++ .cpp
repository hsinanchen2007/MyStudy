### 解题思路
使用数组统计次数

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        
        //字符计数
        vector<int> v(128);
        for(int i = 0; i < s.size(); ++i)
        {
            ++v.at(s.at(i));
        }

        //遍历字符串 去计数数组中找次数为1的
        for(int i = 0; i < s.size(); ++i)
        {
            if(v.at(s.at(i)) == 1)
            {
                return s.at(i);
            }
        }

        return ' ';
    }
};
```