
### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> odd,even;//nums的奇数部分和偶数部分

        for(int num:nums)
            if(num%2==1) odd.push_back(num);
            else even.push_back(num);

        odd.insert(odd.end(),even.begin(),even.end());

        return odd;
    }
};
```