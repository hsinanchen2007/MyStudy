思路：vector可以帮你把啥都做了：

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> dest;
        for (int i = 0; i < m; i++) {
            dest.push_back(nums1[i]);
        }

        for (int j = 0; j < n; j++) {
            dest.push_back(nums2[j]);
        }

        sort(dest.begin(), dest.end());

        nums1.swap(dest);
    }
};