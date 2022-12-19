C++
直接两个库函数搞定

```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>tmp=nums;
        res.push_back(tmp);  //加入本身

        while(prev_permutation(tmp.begin(),tmp.end())) //向前
            res.push_back(tmp);

        while(next_permutation(nums.begin(),nums.end())) //向后
            res.push_back(nums);
        
        return res;
    }
};
```
![深度截图_选择区域_20200203154956.png](https://pic.leetcode-cn.com/b722d73b226f6004b82a6799dc0b2c32c5a0db68aa10d816348c87bca889cf57-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20200203154956.png)

