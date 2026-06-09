### 解题思路
因为nums1是nums2的子集，那我不管三七二十一，将nums2中的所有元素都设置成字典map的key，且初始值val为-1。用两层循环找出nums2里每个元素v右边第一个比它大的元素V，将map中key=v的val改为V，最后根据nums1的元素K查找key=K对应的val并将val覆盖掉nums1中的K，最后返回nums1。

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
         map<int,int> mp;
            stack<int> stack;
    
            for(int value: nums1) {
                mp[value] = -1;
            }
            
            for(int i=0;i<nums2.size();i++) {
                for(int j=i+1;j<nums2.size();j++)
                {
                    if(nums2[i]<nums2[j])
                    {
                        mp[nums2[i]]=nums2[j];
                        break;
                    }
                }
            }
            
            for(int i=0;i<nums1.size();i++) {
                nums1[i] = mp[nums1[i]];
            }
            return nums1;

    }
};
```