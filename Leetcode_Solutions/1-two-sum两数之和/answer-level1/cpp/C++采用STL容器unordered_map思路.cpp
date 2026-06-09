### 解题思路

![QQ截图20200409201729.png](https://pic.leetcode-cn.com/90d9e1618dbef77298a4b932d0be4b15fec1601c93e9df40ac14bcc1729c4aeb-QQ%E6%88%AA%E5%9B%BE20200409201729.png)
提供一个c++版本的思路，使用STL容器unordered_map,该容器采用散列存储，每次查询近似O(1)情况
思路是用散列表存储nums的下标i，对应的Key是nums[i]
每读入一个下标i，查找target-nums[i]是否已存在，如果存在就返回结果，不存在就写入数据
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(myMap.find(target-nums[i]) != myMap.end()){
                res.push_back(myMap.find(target-nums[i])->second);
                res.push_back(i);
                return res;
            }
            else myMap[nums[i]] = i;
        }
        return res;
    }
};
```