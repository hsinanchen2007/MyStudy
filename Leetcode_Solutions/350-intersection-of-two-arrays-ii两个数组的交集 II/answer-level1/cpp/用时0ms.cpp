### 解题思路
题解思路参考分饼干那道题，这题和那题类似，只是那题要求>=这个要求==，以一个数组为基准另一个和这个数组比较就好

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
		int len2=nums2.size(),st=0;
		for(int it:nums1){
			while(st<len2&&nums2[st]<it) ++st;
			if(st==len2) break;
			if(nums2[st]==it) {res.push_back(it);++st;}			
		}
		return res;

    }
};
```