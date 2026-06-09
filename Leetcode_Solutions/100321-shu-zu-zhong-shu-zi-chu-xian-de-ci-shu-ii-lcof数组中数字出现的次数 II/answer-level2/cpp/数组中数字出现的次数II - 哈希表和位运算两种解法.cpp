### 解法一： 哈希表
1. 统计所有数字的次数，采用key ： value的方式存在哈希表中
2. 扫描哈希表，找出只出现一次的那个数字


### 解法一代码
``` cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int n : nums) mp[n] ++;
        int ans;
        for(auto pr : mp){
            if(pr.second == 1){
                ans = pr.first;
                break;
            }
        }
        return ans;
    }
};
```

### 解法二 ： 位运算
1. 值得注意的是：如果某个数字出现3次，那么这个3个数字的**和**肯定能被3整除，则其对应二进制位的每一位的**和**也能被3整除
2. 统计数组中每个数字的二进制中**每一位**的和，判断该和是否能被3整除。
3. 若可以，则只出现一次的数字的二进制数中那一位为0，否则为1

### 解法二代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int cnt = 0;
            for(int n : nums){
                // n & 1 << i 的值大于0即为真
                if(n & 1 << i) cnt++;
            }
            // 构造只出现一次的那个数字，采用异或的方法生成二进制中的每一位
            if(cnt % 3 == 1) ans ^= (1 << i);
        }
        return ans;
    }
};
```