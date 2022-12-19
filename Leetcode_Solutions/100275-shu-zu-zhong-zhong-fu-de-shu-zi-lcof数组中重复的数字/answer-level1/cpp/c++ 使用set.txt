### 解题思路
set的单元素版返回一个二元组（Pair）。成员 pair::first 被设置为指向新插入元素的迭代器或指向等值的已经存在的元素的迭代器。成员 pair::second 是一个 bool 值，如果新的元素被插入，返回 true，如果等值元素已经存在（即无新元素插入），则返回 false。因为在 set 中元素的主键是唯一的，当前插入操作将会检测被插入元素是否等于容器中某个已存在元素，如果是，新的元素将不会被插入，且返回指向这个等值的已经存在的元素（如果当前函数有返回值）。所以set.insert(xx).second是用来确认set元素是否成功插入的标识，也可以用来确认该元素之前没有被插入也没有被处理过。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            if(!st.insert(nums[i]).second){
                return nums[i];
            }
        }
        return 0;
    }
};
```