建立哈希表计数，顺序遍历数组，若表中已存在计数，说明第二次出现，即可返回
```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> dict;
        for(int a:nums){
            if(dict[a]) return a; //判断是否已经出现
            else dict[a]++; //否则，计数加一
        }
        return -1;
    }
};
```
