按照题意，要求过半的元素，
我们从第一个开始往后扫描，记录这个数字res，并且用cnt记录下这个数字出现的次数，
继续往后，如果出现的数字num 等于res，则将cnt加1，否则-1，意思为将res抵消一次，
如果cnt清0，意味着res与非res各半，res被放弃，将记录下一个出现的num为res，重复
操作至结束，存活下来的res即为我们需要的数字。

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {res = num; ++cnt;}
            else (num == res) ? ++cnt : --cnt;
        }
        return res;
    }
};
```
