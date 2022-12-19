### 解题思路
此处撰写解题思路
![350.jpg](https://pic.leetcode-cn.com/6dfe917314898ae89d4f18f70281905744576764a67595a5654be36e0d0f42c1-350.jpg)

### 代码

```cpp
//对nums1建立hash map
//key为值，value为出现次数
//遍历nums2，在map中find，找到且value>0，则输出一个结果，value-1
#include <unordered_map>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> myMap;
        for(vector<int>::iterator ite1 = nums1.begin(); ite1 != nums1.end(); ++ite1)
        {
            //没找到
            if(myMap.find(*ite1) == myMap.end())
            {
                myMap.insert(pair<int,int>(*ite1, 1));
            }
            //找到
            else
            {
                myMap.find(*ite1)->second++;
            }
        }
        vector<int> resVec;
        for(vector<int>::iterator ite2 = nums2.begin(); ite2 != nums2.end(); ++ite2)
        {
            //找到，且value>0
            if(myMap.find(*ite2) != myMap.end() && myMap.find(*ite2)->second > 0)
            {
                resVec.push_back(*ite2);
                myMap.find(*ite2)->second--;
            }
        }
        return resVec;
    }
};
```