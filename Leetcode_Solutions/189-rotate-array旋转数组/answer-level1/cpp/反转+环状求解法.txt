本题思路来源于官方题解
我刚开始想到的时暴力法，结果最后一个样例没有通过

# 方法一：
该方法，很简单，详情可看官方题解
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1) return;
        int len = nums.size();
        k = k % len ;
        
        for(int i = 0, j = len - 1; i < j; i++,j--)
            swap(nums[i],nums[j]);
        
        for(int i = 0,j = k - 1; i < j; i++,j--)
            swap(nums[i],nums[j]);
        for(int i = k,j = len - 1; i < j; i++,j--)
            swap(nums[i],nums[j]);
        
    }
};
```
方法二：环状求解法

![微信截图_20190803110320.png](https://pic.leetcode-cn.com/6bf5ebaf25208112eea4436923779bf852c34150ae69da56438ddc5a07da07ac-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190803110320.png)



```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1) return;
        int len = nums.size();
        k = k % len ;
        
        int count = 0;
        for(int i = 0; count < len; i++){
            int start = i;
            int curent = i;
            int temp = nums[curent];
            do{
                int next = (curent + k) % len;
                swap(temp,nums[next]);
                curent = next;
                count++;
            }while(curent != start);
            
        }
    }
};
```
