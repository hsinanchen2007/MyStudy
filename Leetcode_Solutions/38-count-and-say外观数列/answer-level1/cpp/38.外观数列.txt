### 解题思路
统计

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) 
        {
            string tmp;
            for (int j = 0; j < res.size(); j++) 
            {
                int count = 1;
                while (j+1 < res.size() && res[j+1] == res[j]) 
                { 
                    //统计重复
                    count++;
                    j++;
                }
                tmp += to_string(count) + res[j]; 
            }
            res = tmp; //更新字符串
        }
        return res;
    }
};
```