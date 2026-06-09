利用hash表记录容器nums中  元素以及元素出现的次数
再将hash记录不为1的元素存入另一个vector容器 即可

涉及vector的知识点：
a.back(); //返回a的最后一个元素
a.push_back(5); //在a的最后一个向量后插入一个元素，其值为5

```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) 
    {
        vector<int>arr;
        unordered_map<int,int>hash;
        for(auto x:nums)hash[x]++;//将nums元素存入hash并记录 nums元素出现的次数

        for(auto item:hash)//遍历hash表
        {
            if(item.second!=1)//如果次数不是1次
            {
                arr.push_back(item.first);//将元素存入vector容器中
                return arr.back();//返回arr中最后一个元素
            }
        }
      
        return 0;
    }
};
```
