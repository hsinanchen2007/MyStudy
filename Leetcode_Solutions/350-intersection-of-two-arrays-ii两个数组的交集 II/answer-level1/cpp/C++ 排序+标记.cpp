### 解题思路
1.  先将两个数组排序
2.  若两个数组的值相同，则用jsign记住数组2的j+1的位置，下次从jsign开始遍历。

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {  
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> nbers(0);
        int jsign = 0;
        for(int i = 0; i < nums1.size(); i++)
            for(int j = jsign; j < nums2.size(); j++)
                if(nums1[i]==nums2[j]){
                    nbers.push_back(nums1[i]);
                    jsign = j;
                    jsign++;
                    break;
                }
        
        return nbers;
    }
};
```