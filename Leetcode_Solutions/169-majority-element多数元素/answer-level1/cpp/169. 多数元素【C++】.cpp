### 解题思路

思路很简单，就是遍历数组记录每一个元素的个数，由于最终是要返回元素，所以需要将元素和其个数成对保存，我使用了 `vector<pair<int, int>>` 的数组来存储。

遍历数组，先到 `aNums[]` 中查找 `num` 是否已存在，如果已存在则将其个数+1；不存在，则将其添加到 `aNums[]` 并将其个数初始化为1。

题目已经说明“**给定的数组总是存在多数元素**”，所以可以确定出现次数大于 `⌊ n/2 ⌋` 的多数元素有且仅有一个。所以每遍历一个元素，我们就判断其个数是否大于 `nums.size() / 2` ，一旦有一个元素的个数大于 `nums.size() / 2` 则说明这个元素就是要求的多数元素，直接将该元素返回即可。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //可作为跳出循环的条件，因为多数元素只存在一个
        int low = nums.size() / 2;
        vector<pair<int, int>> aNums;//保存元素及其个数
        //统计不同元素的个数，一旦某个元素的个数大于low则可直接返回这个元素
        for (auto num : nums) {
            int quantity = 0;//num的个数
            //查找aNums[]中是否已有num的记录
            for (int i = 0; i < aNums.size(); i++) {
                //如果有的话，将其数量+1，并更新quantity
                if (aNums[i].first == num) {
                    aNums[i].second++;
                    quantity = aNums[i].second;
                }
            }
            //quantity==0表面num第一次遇到
            if (quantity == 0) {
                aNums.push_back({ num,1 });//将其添加到aNums[]中，数量初始化为1
                quantity = 1;//更新num的数量为1
            }
            if (quantity > low)
                return num;
        }
        return 0;//遍历完整个数组之前一定能返回结果，不会运行到这一步
    }
};
```