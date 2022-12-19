# 方法一：哈希暴力求解（不满足不使用额外空间）
```
//哈希暴力求解

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size();i++){
            if(m.find(nums[i]) != m.end()){
                m.erase(m.find(nums[i]));
            }else{
                m[nums[i]] = 1;
            }
        }
        return m.begin()->first;
    }
};
```

# 方法二：异或法
```
//异或
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int v=0;
        for(int i=0; i<nums.size(); i++){
            v ^= nums[i];
        }
        return v;
    }
};
```
