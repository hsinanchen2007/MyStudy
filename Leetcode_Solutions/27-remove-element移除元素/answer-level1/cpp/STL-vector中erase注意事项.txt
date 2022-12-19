这就是个STL的简单运用，但是这里强调一下：
nums.erase(it)删除后,it是个野指针，所以在循环for里，it不能直接++，要分情况
如果找到对应的it,先赋值给临时迭代器temp,按temp删除；
这样it不变，但后面的元素迁移，相当于it指向了后一个元素；如果不是val，it直接后移
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it=nums.begin();it!=nums.end();)
        {
            if(*it==val)
            {
                auto temp=it;
                nums.erase(temp);  
            }
            else
                it++;
        }
        return nums.size();
    }
};
```
