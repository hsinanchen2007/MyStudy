### 解题思路
![1583393704(1).jpg](https://pic.leetcode-cn.com/0bb1117fc31eb8f2f0735e410cc45254d8013957788934e4486551b7296b29a2-1583393704\(1\).jpg)
执行用时纯属偶然


### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {       
        vector<int> ans(num_people);//定义空数组
        if(candies == 0) return ans;
        int total = 0;
        int i = 0;//等差数列中的第i个
        while(total < candies){
            i++;
            total += i;
        }//一共要分i次
        total = total - i;
        for(int n = 0; n<i-1; n++){
            ans[n % num_people] += n+1;
        }
        ans[(i-1) % num_people] += candies - total;
        return ans;
    }
};
```