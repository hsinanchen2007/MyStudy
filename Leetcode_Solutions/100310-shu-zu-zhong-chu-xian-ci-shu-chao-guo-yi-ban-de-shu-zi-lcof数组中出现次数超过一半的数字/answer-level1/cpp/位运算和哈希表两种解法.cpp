### 方法一 位运算
给出输入`[1,2,3,3,3]`，将这几个数字写成二进制数(整型32位，这里只写出后面4位)`[0001, 0010, 0011, 0011, 0011]`。在这4位二进制数字中。**各自**的**最高位**分别为`[0，0，0，0]`，则最高位出现最多的数字是二进制`0`。同理，高二位出现最多的二进制数字为`0`，高三位出现最多的二进制数字为`1`，最低位出现最多的二进制数字为`1`。则4位出现最多的二进制数字拼起来为`0011`，值为`3`，即结果。


### 方法一 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i < 32; i++){
            int cnt = 0;
            for(int n: nums){
                if(n & 1 << i) cnt ++;
            }
            if(cnt > n / 2) ans ^= 1 << i;
        }
        return ans;
    }
};
```

### 方法二 哈希表
1. 使用`unordered_map`数据结构，扫一遍给定数组，存储每个数字出现的次数。
2. 再扫一遍哈希表，找出出现次数超过一半的数字


### 方法二 代码

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans;
        for(int n: nums) {
            mp[n]++;
        }
        for(auto pr: mp){
            if(pr.second > n / 2) ans = pr.first;
        }
        return ans;
    }
};

```
