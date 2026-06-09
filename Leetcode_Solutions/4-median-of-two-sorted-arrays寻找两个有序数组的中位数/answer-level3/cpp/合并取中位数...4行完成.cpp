感觉这种用merge挺方便的，速度居然也不慢
执行用时 :20 ms, 在所有 C++ 提交中击败了78.11%的用户
内存消耗 :9.9 MB, 在所有 C++ 提交中击败了31.92%的用户
```
        int t = nums1.size()+nums2.size();
		vector<int> vec(t);
		merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),vec.begin());
            return t%2?vec[t/2]:(vec[t/2]+vec[t/2-1])/2.0;
```
