### 解题思路
方法一：遍历数组，将数组中每个数作为key存入map中，插入map前先查询（n^2）map中是否已经含有该key，若有则数字重复
方法二（更优！）：先对数组进行排序（nlogn），再遍历排序后数组，比较（n）相邻的两个数是否相同
### 代码

```cpp
class Solution {
    //方法一：遍历数组，将数组中每个数作为key存入map中，插入map前先查询map中是否已经含有该key，若有则数字重复
/*public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m1;
        for (auto i = nums.cbegin(); i != nums.cend(); i++) {
            auto pos = m1.find(*i);
            if(pos != m1.end()){
                return true;
            }else {
                m1[*i] = 1;
            }
        }
        return false;
    }
};*/
    //方法二（更优！）：先对数组进行排序（nlogn），再遍历排序后数组，比较相邻的两个数是否相同
    public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty())
            return false;
        sort(nums.begin(), nums.end());
        int temp = nums.front();
        int flag = 0;
        for(int n : nums) {
            if(n==temp&&flag==1)
                return true;
            else
                temp=n;
            flag=1;
        }
        return false;
    }
};
```