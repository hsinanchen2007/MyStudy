### 解题思路
把nums2放到nums1里（题目说了nums1空间>=m+n，所以可以直接把nums2放到nums1后面去）。
再调用sort进行排序就好了

### 代码

```cpp
cclass Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 0,1,2...m-1,m,m+1,...
        // 0,1,2...n-1
        int j = 0;   
        for(int i = m;i < m+n;i++){  //将nums2的所有元素放在nums1多出来的那部分空间里
            nums1[i] = nums2[j]; 
            ++j;
        }
        sort(nums1.begin(),nums1.end());  //此时nums1包含了原来的nums2，但是是无序的。排序即可
    }
};
```