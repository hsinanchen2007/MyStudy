### 解题思路
寻找数组中k绝对值的pair个数。
采用双指针。和字符串元音反转类似

还有一种是用集合方法。就是把所有的数字放进集合中，判断目标数存不存在。有就加加。

### 代码

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res=0;
        sort(nums.begin(),nums.end());
        int p1=0,p2;
        int des;
        for(int p1=0;p1<nums.size();){
             des=nums[p1]+k;
             p2=p1+1;
             while(p2<nums.size()&&nums[p2]<des) ++p2;
             if(p2==nums.size()) return res;
             if(nums[p2]==des) ++res;
            // if(nums[p2]>des) 
            while(p1+1<nums.size()&&nums[p1]==nums[p1+1]) p1=p1+1;
            ++p1;
            
        }
        return res;
    }
};
```