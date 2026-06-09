### 解题思路
1. 数组要进行排序
2. 用两个指针分别指向两个数组
3. 当两个指针的指向的元素相等时，把该元素加入set，两个指针值+1
4. 若第3条不成立时，将值较小的那个指针值+1，直到遍历完数组
5. 将set的元素复制到vector中

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> s;
        if(nums1.empty() || nums2.empty()) return result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i<nums1.size() && j<nums2.size()){
            int d = nums1[i] - nums2[j];
            if(d==0){
                s.insert(nums1[i]);
                i++;
                j++;
            } 
            else if(d<0) i++;
            else j++;
        }
        result.assign(s.begin(),s.end());
        return result;
    }
};
```