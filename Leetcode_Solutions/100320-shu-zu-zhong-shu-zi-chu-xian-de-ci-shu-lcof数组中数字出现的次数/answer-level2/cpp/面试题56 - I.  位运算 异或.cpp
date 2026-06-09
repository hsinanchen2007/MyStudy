```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int resXOR = 0;
        for (auto x : nums) 
            resXOR ^= x;

        int n = 0;                    // 寻找最低位低1
        while ((resXOR & 1) == 0) {   // == 优先级高于 &
            resXOR = resXOR >> 1;
            n ++;
        }

        int num1 = 0, num2 = 0;
        for(auto x : nums) {    // 按第n位是不是1分成两部分
            if ((x >> n) & 1)
                num1 ^= x;
            else
                num2 ^= x;
 
        }
        return {num1, num2};

    }
};
```