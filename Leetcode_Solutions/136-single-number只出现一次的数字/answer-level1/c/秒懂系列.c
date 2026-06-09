

```c
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // a ⊕ b ⊕ a = b
        // a ⊕ 0 = a
        // a ⊕b ⊕ c = a ⊕ (b ⊕ c) = (a ⊕ b) ⊕ c 
        int res=0;
        for(int i:nums)
            res^=i;
        return res;

    }
};
```
