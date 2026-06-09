### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++)
            if(isDividSelf(i))
                ans.push_back(i);
        return ans;
    }

    //判断是否为自除数
    bool isDividSelf(int x){
        int n = x;
        while(n > 0)
        {
            int d = n % 10;
            if(d == 0 || x % d != 0)
                return false;
            n /= 10;
        }
        return true;
    }
};
```