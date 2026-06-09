### 解题思路
1.unordered_map键值存放元素，值存放地址指针。
2.若在unordered_map中找到相同的键值，查找两个之间的地址差是否大于k值，小于k值就返回true。
3.遍历完数组若还无任何情况则返回false。

### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
int res = k + 1;
    for(int i = 0;i < nums.size();i++){
        if(hash.count(nums[i])){
            res = min(res,i - hash[nums[i]]);
            if(res <= k) return true;
        }
        hash[nums[i]] = i;
    }
    return false;
    }
};
```