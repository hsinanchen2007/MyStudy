![QQ浏览器截图20200306135214.jpg](https://pic.leetcode-cn.com/f4748c8b6ac477e661e1f4ab0886374a63915077fe130f993ca56e43096fa4c9-QQ%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20200306135214.jpg)

### 解题思路
投票算法，因为主要元素的数量超过除去主要元素外的总数量，即sum(主要元素)-sum(其他元素)>0,
所以得到以下代码：


### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int countn=0;
        for(int i=0;i<nums.size();i++){
            if(ans==nums[i])countn++;
            else countn--;
            if(countn==0){
                ans=nums[i];
                countn=1;
            }
        }
        countn=0;
        for(int i : nums){
            if(ans==i)countn++;
        }
        return countn>nums.size()/2?ans:-1;
    }
};
```