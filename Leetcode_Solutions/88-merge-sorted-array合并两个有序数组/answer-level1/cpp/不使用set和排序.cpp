![image.png](https://pic.leetcode-cn.com/a21358c43cf30b15977c5043b12f0d322d00ff2d33d64e8d7ff80e433f849346-image.png)

代码如下：
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int i = m-1, j = n-1;
        int index = n1-1;

        if(m == 0) {
            nums1 = nums2;
            return;
        }

        while(i >= 0 && j >= 0) {
            int v1 = nums1[i];
            int v2 = nums2[j];
            if(v1 < v2) {
                nums1[index] = v2; 
                j--;
            } else {
                nums1[index] = v1;
                i--;
            }
            index--;
        }
        while(j >= 0) {
            nums1[index--] = nums2[j--];
        }
    }
};
```

