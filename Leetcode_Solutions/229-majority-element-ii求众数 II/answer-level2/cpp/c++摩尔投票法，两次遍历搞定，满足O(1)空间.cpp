参考169题求众数，使用摩尔投票法。
不同于169的是这里需要两组摩尔投票结构，当有新的数来时，如果两个摩尔数字有空位置则填充一个空位，否则判断是否与两个最多数字之一相等，相等对应数字计数器+1，否则两个计数器都要-1。
第一次遍历找到出现次数最多的两个数字；再遍历一次对出现最多的两个数重新计数，最后判断个数是否符合条件返回结果。
```
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, maj1 = 0, maj2 = 0;
        for(auto num:nums){
            if(cnt1 == 0 ||  maj1 == num) {
                if(maj2 == num) cnt2++;
                else{cnt1++; maj1 = num;}
            }else if(cnt2 == 0 || maj2 == num) {
                cnt2++; maj2 = num;
            }else{
                cnt1--; cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for(auto num:nums){
            if(num == maj1) cnt1++;
            else if(num == maj2) cnt2++;
        }
        vector<int> results;
        if(cnt1 > nums.size()/3) results.push_back(maj1);
        if(cnt2 > nums.size()/3) results.push_back(maj2);
        return results;
    }
};
```
![微信图片_20200102110336.png](https://pic.leetcode-cn.com/b50aee1ae0daa0aac0f966865ef22f4805d82d0b2177c49d78b25e360f4a9b4b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200102110336.png)

