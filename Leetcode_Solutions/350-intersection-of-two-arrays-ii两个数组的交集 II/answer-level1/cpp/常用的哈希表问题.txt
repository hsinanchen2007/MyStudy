### 解题思路
常遇到在检测到一个相等元素后，需要删除掉对比数组中的该元素。惯用套路。
T299猜数字游戏中也是一样的做法。
### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> hashmap;
        for(int i=0;i<nums1.size();i++)
        {
            hashmap[nums1[i]]++;  //都为1
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(hashmap[nums2[i]]>0)
            {
                res.push_back(nums2[i]);
                hashmap[nums2[i]]--;
            }
        }
        return res;
    }
};
```