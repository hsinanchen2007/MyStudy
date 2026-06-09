### 解题思路
暴力解
![image.png](https://pic.leetcode-cn.com/8ec0a5159c067db1ee4750901c55d6ff975ac66ae700226bd848cfcde54f54e7-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int index = 0;
        while (candies > 0) {
            for (int i = 0; i < num_people; i++) {
                index++;
                if (candies < index ){
                    ans[i] += candies;
                    candies -= index;
                    break;
                } else {
                    ans[i] += index;
                }
                candies -= index;
            } 
        }
        return ans;
    }
};
```