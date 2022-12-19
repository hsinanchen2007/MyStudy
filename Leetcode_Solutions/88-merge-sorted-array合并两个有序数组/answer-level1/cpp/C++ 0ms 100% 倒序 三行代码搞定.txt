
```
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n -1,j = m - 1, k= n - 1;
        while(k >= 0)
            nums1[i--] = j>=0&&nums1[j] > nums2[k] ? nums1[j--] : nums2[k--];
    }
```
