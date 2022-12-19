## 思路
一个为n的数组`nums`有`2^n`的子集，我们可以用比特长度超过n的数字`i`来表示这个子集。假如有一个两个数组的元素`[1 2]`, 那么我们可以用
`0x00`表示`[   ]`
`0x01`表示`[  2]`
`0x10`表示`[1  ]`
`0x11`表示`[1  2]`
用这种方法我们可以通过自加`i`穷举出所有可能的子集。 组合数非常庞大，一个64个元素子集数量便有`2^64 = 18446744073709551616`的可能性，大约一百八十四亿亿。用一个`uint64_t`的数字就可以记录长达64的数组的子集了。
## C++ 代码



```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        uint64_t val = 0, max = (1 << nums.size()) - 1, num = 0, i = 0;
        vector<vector<int>> items;
        vector<int> item;
        while (val <= max) {
            item.clear();
            num = val;
            i = 0;
            while (num) {
                if (num & 1) item.push_back(nums[i]);
                num >>= 1;
                ++i;
            }
            ++val;
            items.push_back(item);
        }
        return items;
    }
};
```