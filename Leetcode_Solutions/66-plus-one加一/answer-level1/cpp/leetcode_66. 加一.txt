![1.png](https://pic.leetcode-cn.com/460167ca4364356a20824056b37427496caa9a531d0fc95ba7e9d13e33a739a4-1.png)


```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(len == 1)
        {
            if(digits[0] < 9) 
            {
                ++(digits[0]);
                return digits;
            }
            if(9 == digits[0]) digits.push_back(0);
            digits[0] = 1;
            return digits;
        }
        
        for(int i = len - 1; i > -1; i--)
        {
            if(digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            if(9 == digits[i])
                digits[i] = 0;
            if(0 == i && 0 == digits[i])
                digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

```

