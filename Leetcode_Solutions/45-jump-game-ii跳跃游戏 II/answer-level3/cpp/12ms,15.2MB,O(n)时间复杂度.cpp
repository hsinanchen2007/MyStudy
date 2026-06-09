### 解题思路
此处撰写解题思路
最小的步数一定是从前面的步数多走几步开始的，能少走肯定不能多
我引入了一个步长length，表示本次位置所能走的最大步数，只有当步数加上当前坐标大于动态方程中的值时，才有跳跃的可能性
与此同时，跳跃的可能性有了，判断发生跳跃的可行性，如果此前要跳的位置早已有比我跳跃更少的次数，我又何必要跳。
所以跳跃的位置从第一个大于容器大小的值开始。可能跳跃下表为j=v.size()；j<nums.size(),且在我步长length控制的范围
那就能跳，如果不在了就继续下次循环，循环之前判断j只要j刚好到最后一个下标，那就break即可
### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)
        return 0;
        int cnt=0;
        vector<int> v;
        v.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            //有必要聪明的引入一个长度，存放当前数组的能跳到的最长步数。
            int length=nums[i];//能比当前v多一步的最小状态
            if(i+length+1>v.size())
            {
                int j=v.size();
                 while(j-i<=length && j<nums.size())
                {
                v.push_back(v[i]+1);
                j++;
                }
                if(j==nums.size())
                {
                    break;
                }
            }
        }
        return v[v.size()-1];
    }
};
```