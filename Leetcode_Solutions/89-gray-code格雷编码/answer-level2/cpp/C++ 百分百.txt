### 解题思路
依照格雷编码的定义，每个数i的对应的格雷编码就是i右移1位，再与自身异或  i^(i>>1)

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0)return {0};
        if(n==1)return {0,1};
        
        vector<int> res = {0,1};
        for(int i=2;i<pow(2,n);i++)
        {
            int tmp = i^(i>>1);
            res.push_back(tmp);
        }
        return res;

    }
};
```