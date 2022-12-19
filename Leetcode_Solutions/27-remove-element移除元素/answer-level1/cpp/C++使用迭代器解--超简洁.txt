使用迭代器，如果相等则删除该元素，返回一个指向后一个元素的迭代器；不等则向后移动。
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto p=nums.begin();p!=nums.end();){
            if(*p!=val){
                ++p;
            }else{
                p=nums.erase(p);
            }
        }
        return nums.size();
    }
};
```
