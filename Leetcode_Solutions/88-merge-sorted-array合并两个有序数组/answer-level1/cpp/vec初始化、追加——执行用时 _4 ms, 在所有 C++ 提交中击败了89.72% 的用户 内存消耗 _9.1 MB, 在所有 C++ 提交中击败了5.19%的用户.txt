### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	vector<int> nums1_truc(nums1.begin(), nums1.begin()+m);
    	vector<int> nums2_truc(nums2.begin(), nums2.begin()+n);
//    	cout << "nums1_truc.size() = " << nums1_truc.size() << endl;
//    	cout << "nums2_truc.size() = " << nums2_truc.size() << endl;
    	vector<int> nums_merge(nums1.begin(), nums1.begin()+m);
    	nums_merge.insert(nums_merge.end(), nums2.begin(), nums2.begin()+n);
//    	//debug
//    	for(auto& iter:nums_merge){
//    		cout << iter << " ";
//    	}
//    	cout << endl;
//    	cout << "After sort:" << endl;
    	std::sort(nums_merge.begin(), nums_merge.end());
//    	//debug
//    	for(auto& iter:nums_merge){
//    		cout << iter << " ";
//    	}
    	nums1.clear();
    	nums1.insert(nums1.begin(), nums_merge.begin(), nums_merge.end());
//    	//debug
//    	cout << "\nFinal nums1:" << endl;
//    	for(auto& iter:nums_merge){
//    		cout << iter << " ";
//    	}
    }
};
```