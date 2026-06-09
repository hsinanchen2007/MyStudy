### 解题思路
用函数next_permutation()或者pre_permutation()

### 代码

```cpp
class Solution {
public:
    vector<string> permutation(string S) {
        std::ios::sync_with_stdio(false);
        sort(S.begin(),S.end());
        vector<string> ans;
        while(1){
                ans.push_back(S.substr(0,S.size()));
            if(!next_permutation(S.begin(),S.end()))break;   
        }
        return ans;
    }
};
```
![屏幕快照 2020-02-15 上午10.22.20.png](https://pic.leetcode-cn.com/e7e555e34592cd73093c1d10fc7b9ad1ea02a7ee2b54f531eb37041f82760b12-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-15%20%E4%B8%8A%E5%8D%8810.22.20.png)
