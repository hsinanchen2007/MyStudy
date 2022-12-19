```cpp

// //1. map
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> map;
//         for (auto x : nums)
//             map[x] ++;
        
//         for (auto it = map.begin(); it != map.end(); it++)
//             if (it->second == 1)
//                 return it->first;
//         return 0;
//     }
// };



//2. 位运算，统计二进制每一位1出现的次数，每一位%3后结果就是这个数
class Solution {
private:
    int freq[32]= {0};

    void update(int freq[], int x) {
        unsigned int bitMask = 1;
        for (int i = 0; i < 32; i++) {
            freq[i] += (bitMask & x )? 1 : 0;
            bitMask = bitMask << 1;
        }
    }

public:
    int singleNumber(vector<int>& nums) {
        for (auto x : nums) 
            update(freq, x);

        int res = 0;
        for (int i = 31 ; i > 0; i--) {
            res += freq[i] % 3;
            res = res << 1;
        }
        res += freq[0] % 3;
        return res;

    }
};
```