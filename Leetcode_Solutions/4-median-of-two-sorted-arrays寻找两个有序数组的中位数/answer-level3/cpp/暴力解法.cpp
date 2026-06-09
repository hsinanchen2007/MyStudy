### 解题思路
时间复杂度O(m+n)应该很大了，运行结果有些出人意料
![截屏2020-03-18下午1.53.18.png](https://pic.leetcode-cn.com/10d18d413f4226e72ae6d5dfcac8a0a5e5f0c6756170b56224e5294fe90bb9ab-%E6%88%AA%E5%B1%8F2020-03-18%E4%B8%8B%E5%8D%881.53.18.png)

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int kn = (s1+s2-1)/2;
        if((s1+s2)%2) {
            if(s1 == 0) return nums2[kn];
            if(s2 == 0) return nums1[kn];
        } else {
            if(s1 == 0) return (nums2[kn]+nums2[kn+1])/2.f;
            if(s2 == 0) return (nums1[kn]+nums1[kn+1])/2.f;
        }

        int k1 = 0, k2 = 0, k = 0;
        int lastN = 0;
        while(k<=kn && k1<s1 && k2<s2) {
            int n1 = nums1[k1];
            int n2 = nums2[k2];
            if(n1<n2) {
                lastN = n1, k1++;
            }
            else {
                lastN = n2, k2++;
            }
            k++;
        }

        if(k==kn + 1) {
            if((s1+s2)%2) {
                return lastN;
            }
            else {
                int n1 = k1 < s1 ? nums1[k1]: INT_MAX;
                int n2 = k2 < s2 ? nums2[k2]: INT_MAX;
                return (lastN + min(n1, n2))/2.f;
            }
        }

        int lastK = kn + 1 - k;
        if((s1+s2)%2) {
            //奇数
            return k1 == s1 ? nums2[k2+lastK-1] : nums1[k1+lastK-1];
        }
        if(k1 == s1) {
            return (nums2[k2+lastK-1] + nums2[k2+lastK])/2.f;
        } else {
            return (nums1[k1+lastK-1] + nums1[k1+lastK])/2.f;
        }
    }
};
```