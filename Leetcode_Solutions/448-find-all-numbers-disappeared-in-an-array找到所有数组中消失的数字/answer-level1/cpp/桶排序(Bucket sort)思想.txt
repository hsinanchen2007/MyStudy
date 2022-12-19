看到这道题,我就想到了桶排序,创建一个中间变量数组temp,遍历数组nums,让temp数组中下标对应nums[i]的值加一,最后只需要寻找temp[1]到temp[n]中谁对应的值是0,其下标就是我们需要寻找的值,代码如下:
```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         vector<int>res;
        vector<int>temp(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            temp[nums[i]]++;
        for (int i = 1; i < temp.size(); i++)
            if (temp[i] == 0)
                res.push_back(i);
        return res;
    }
};
```