# 解题思路
1.首先判断向量nums是否为空，为空直接返回0
2.对向量nums进行sort排序
3.去除向量nums中的重复元素后将元素移至数组num中
4.对数组num进行遍历求得最长连续序列长度
# AC代码
```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())        //判空
            return 0;
        const int n = nums.size();
        int num[n], cnt = 1, result = 1, temp;  //初始最长长度为1
        sort(nums.begin(), nums.end());     //对nums排序
        num[0] = nums[0];
        //去除重复元素并记录去重后数组的长度
        for(int i = 1; i < n; i++){
            num[cnt] = nums[i];
            if(nums[i] != nums[i-1])
                cnt++;
        }
        for(int i = 0; i < cnt - 1; i++){
            temp = 1;
            while(i < cnt - 1 && num[i] == num[i+1] - 1){
                temp++;
                i++;
            }
            result = max(result, temp);     //记录最长连续序列长度
        }
        return result;
    }
};
```

