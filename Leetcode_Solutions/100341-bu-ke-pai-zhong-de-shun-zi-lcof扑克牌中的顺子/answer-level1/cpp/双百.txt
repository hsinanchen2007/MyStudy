### 解题思路

### 代码

```cpp
class Solution {
public:
bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int hash[14] = {0};
    int cnt = 0;
    int i;
    for(i = 0 ; i < nums.size() ; ++i)
    {
        if(nums[i] == 0)
        {
            cnt++;
        }
        else
            break;
    }
    int pre = nums[i];
    hash[pre]++;
    i++;
    for( ; i < nums.size() ; ++i)
    {
        hash[nums[i]]++;
        if(hash[nums[i]] > 1)   //如果出现除0以外的重复数字，那么肯定不能成为顺子
            return false;
        if(nums[i] != pre + 1)
        {
            //cout<<nums[i]<<" "<<pre<<endl;
            if(!cnt || nums[i] - pre > cnt + 1)     //如果现有的0不足以补全空缺
                return false;
        }
            pre = nums[i];
    }
    return true;
}
};
```