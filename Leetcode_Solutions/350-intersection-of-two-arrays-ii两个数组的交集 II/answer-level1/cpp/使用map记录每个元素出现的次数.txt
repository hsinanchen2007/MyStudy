### 解题思路
遍历第一个vector，记录下每个元素出现的次数；
再第二个vector中，找到次数大于0的值，并保存就可以了
### 代码

```cpp
class Solution {
public:
    //搞个map，记录每个元素出现的次数
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> index;
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            index[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(index[nums2[i]] > 0){
                res.push_back(nums2[i]);
                index[nums2[i]]--;
            }
        }
        return res;
    }
};
```