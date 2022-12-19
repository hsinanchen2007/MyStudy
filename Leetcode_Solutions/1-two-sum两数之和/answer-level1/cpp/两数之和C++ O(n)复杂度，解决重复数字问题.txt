思路：对当前数字nums[i]进行判断，当该数字与已有map中的数字进行组合能得到taget时，返回两个数字对应的序号i。
此思路可以解决重复数字的问题，因为是两数之和，一个数为当前还未存入map的数，另一个数必定是map中的数。

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> vec;
        for(int i=0;i<nums.size();i++)
        {
            int b=target-nums[i];
            if(m.count(b)){//count与find或者下标查找的不同之处需要了解，有则返回1，没有则返回0.
                vec.push_back(m[b]);
                vec.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return vec;
    }
};
```
