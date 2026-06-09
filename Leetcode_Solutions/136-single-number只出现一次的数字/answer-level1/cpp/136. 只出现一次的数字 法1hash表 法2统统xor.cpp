### 解题思路
此处撰写解题思路

### 代码
```cpp
//线性时间复杂度下，找出只出现一次的元素
//解法1：采用额外空间，扫描两次
//     额外空间：一个unordered_map
#include <unordered_map>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> myMap;
        for(vector<int>::iterator iteNums = nums.begin(); iteNums != nums.end(); ++iteNums)
        {
            if(myMap.find(*iteNums) == myMap.end())
            {
                myMap.insert(make_pair(*iteNums,1));
            }
            else
            {
                myMap.find(*iteNums)->second++;
            }
        }
        for(vector<int>::iterator iteNums = nums.begin(); iteNums != nums.end(); ++iteNums)
        {
            if(myMap.find(*iteNums)->second == 1)
            {
                return *iteNums;
            }
        }
        return 0;
    }
};
```


```cpp
//解法2：xor的方法
//相同数xor之后为0，所有数xor之后即可得到结果


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int resNum = 0;
        for(vector<int>::iterator ite = nums.begin(); ite != nums.end(); ++ite)
        {
            resNum = resNum xor (*ite);
        }
        return resNum;
    }
};
```
![136_xor.jpg](https://pic.leetcode-cn.com/495de860e0d7c1c86a238428bd5e5ce968e4292893b999d02204c172a8770109-136_xor.jpg)
