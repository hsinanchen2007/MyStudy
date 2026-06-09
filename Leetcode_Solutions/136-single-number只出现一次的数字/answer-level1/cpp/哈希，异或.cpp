### 解题思路
哈希，异或

### 代码

#### 哈希

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> p;
        for(int i = 0; i < nums.size(); i++){
            if(p.find(nums[i]) != p.end())p.erase(nums[i]);
            else p[nums[i]] = 1;
        }
        return p.begin()->first;
    }
};
```

#### 异或
0与任意值异或为任意值，任意值两次异或为零。

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int p = 0;
        for(int i = 0; i < nums.size(); i++){
            p ^= nums[i];
        }
        return p;
    }
};
```