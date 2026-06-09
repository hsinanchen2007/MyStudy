遍历数组，只要遇到0则删除，count加1（计0的个数），最后在末尾补上count个0即可。因为使用了迭代器，要注意的是避免迭代器失效。

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(auto it=nums.begin(); it!=nums.end(); ){
            if(*it == 0){
                it = nums.erase(it);
                count ++; 
            }
            else{++it;}
        }
        nums.insert(nums.end(), count, 0);
    }
};
```