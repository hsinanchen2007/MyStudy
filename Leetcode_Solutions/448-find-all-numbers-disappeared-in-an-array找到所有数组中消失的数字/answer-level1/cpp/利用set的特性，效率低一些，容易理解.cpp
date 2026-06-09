### 解题思路
因为STL中的set具有自动排序和去重的功能，所以先新建一个set变量，然后遍历nums中的所有数并插入set中，之后遍历1-n，看哪个数字在set中没有，则该数就是我们要找的数。但是该方法的效率较低，执行时间较长。

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> s;
        set<int>a;
        for(int i=0;i<nums.size();i++)
        {
            a.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
           if(a.count(i+1)) 
           {
               continue;
           }  
           else{
               s.push_back(i+1);
           }    
        }
       return s;
    }
};
```