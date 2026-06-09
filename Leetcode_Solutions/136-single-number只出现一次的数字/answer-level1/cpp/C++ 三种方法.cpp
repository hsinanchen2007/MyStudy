### 已存在哈希表则删除否则插入
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uset;
        for (int &num: nums) {
            auto res = uset.insert(num);
            if (!res.second) uset.erase(res.first);
        }
        return *uset.begin();
    }
};
```

### 2*(a+b+c)-(a+a+b+b+c)=c
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uset;
        uset.insert(nums.begin(), nums.end());
        int res = 0;
        for (auto num: uset) {
            res += num;
        }
        res *= 2;
        for (auto num: nums) {
            res -= num;
        }
        return res;
    }
};
```

### a^b^a=a^a^b=b
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num: nums) {
            res ^= num;
        }
        return res;
    }
};
```