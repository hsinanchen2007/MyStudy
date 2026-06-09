要寻找两个数组的中位数，关键是要对这两个数组进行适当划分，使得左右两边数量相等（或差1），且左边最大数<=右边最小数。思路：
1. 将两个数组区分为更长的那个和更短的那个。
2. 排除掉有一个数组为空的情况。
3. 二分法确定长数组的划分位置。
4. 根据左右两边数量相等的规则，确定短数组的划分位置。
5. 如果短数组的划分位置越界，则划分失败，回到第3步。
6. 检查划分位置两旁的数是否符合左边<=右边的规则，需要注意一些特殊情况。
7. 检查通过则计算出中位数，检查不通过则回到第3步。

划分位置的说明：划分位置在划分索引的右边。如数组[0,1,2,3]，划分索引为1表示划分位置在1和2之间；划分在数组的左右两侧也是可以的，因此划分索引可在-1到n-1之间取值。

```
class Solution {
public:
    void getMedian(vector<int>& nums, int m, double& median) {
        if (m%2) { // odd
            median=(double)nums[m/2];
        } else {
            median=(double)(nums[m/2-1]+nums[m/2])/2;
        }
    }
    
    // if two nums are divided successfully, return true and store the median
    // if not, return false and tell divide_long should go left or right
    bool divideOk(vector<int>& nums_long, vector<int>& nums_short, int m, int n,
                  int divide_long, int divide_short, double& median, bool& go_left) {
        if (divide_short<-1) {
            go_left=true;
            return false;
        } else if (divide_short>n-1) {
            go_left=false;
            return false;
        }
        bool odd=(m+n)%2;
        // nums_long is divided at left side; nums_short must be divided at right side
        if (divide_long==-1) {
            if (odd) {
                median=(double)nums_long[0];
            } else {
                median=(double)(nums_short[n-1]+nums_long[0])/2;
            }
            return true;
        }
        // nums_long is divided at right side; nums_short must be divided at left side
        if (divide_long==m-1) {
            if (odd) {
                median=(double)nums_long[m-1];
            } else {
                median=(double)(nums_long[m-1]+nums_short[0])/2;
            }
            return true;
        }
        // nums_short is divided at left side; now nums_long must be divided not at side
        if (divide_short==-1) {
            if (nums_long[divide_long]<=nums_short[0]) {
                int smaller=(nums_long[divide_long+1]<nums_short[0])?
                    nums_long[divide_long+1]:nums_short[0];
                if (odd) {
                    median=(double)smaller;
                } else {
                    median=(double)(nums_long[divide_long]+smaller)/2;
                }
                return true;
            } else {
                go_left=true;
                return false;
            }
        }
        // nums_short is divided at right side; now nums_long must be divided not at side
        if (divide_short==n-1) {
            if (nums_short[n-1]<=nums_long[divide_long+1]) {
                if (odd) {
                    median=(double)nums_long[divide_long+1];
                } else {
                    int larger=(nums_long[divide_long]>nums_short[n-1])?
                        nums_long[divide_long]:nums_short[n-1];
                    median=(double)(larger+nums_long[divide_long+1])/2;
                }
                return true;
            } else {
                go_left=false;
                return false;
            }
        }
        // now nums_long and nums_short must be divided not at side
        if (nums_long[divide_long]<=nums_short[divide_short+1] &&
           nums_short[divide_short]<=nums_long[divide_long+1]) {
            int smaller=(nums_long[divide_long+1]<nums_short[divide_short+1])?
                    nums_long[divide_long+1]:nums_short[divide_short+1];
            if (odd) {
                median=(double)smaller;
            } else {
                int larger=(nums_long[divide_long]>nums_short[divide_short])?
                        nums_long[divide_long]:nums_short[divide_short];
                median=(double)(larger+smaller)/2;
            }
            return true;
        } else if (nums_long[divide_long]>nums_short[divide_short+1]) {
            go_left=true;
            return false;
        } else {
            go_left=false;
            return false;
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>& nums_long=(m<n)?nums2:nums1;
        vector<int>& nums_short=(m<n)?nums1:nums2;
        m=nums_long.size();
        n=nums_short.size();
        double median=0;
        if (n==0) {
            getMedian(nums_long,m,median);
            return median;
        }
        int half=(m+n)/2;
        int begin_long=0;
        int end_long=m-1;
        int divide_long=(begin_long+end_long)/2;
        int divide_short;
        bool go_left=true;
        while (true) {
            divide_short=half-divide_long-2;
            if (divideOk(nums_long,nums_short,m,n,divide_long,divide_short,median,go_left)) {
                return median;
            } else {
                if (go_left) {
                    end_long=divide_long;
                } else {
                    begin_long=divide_long;
                }
                int mid_long=(begin_long+end_long)/2;
                if (divide_long==mid_long) {
                    if (go_left) {
                        divide_long--;
                    } else {
                        divide_long++;
                    }
                } else {
                    divide_long=mid_long;
                }
            }
        }
    }
};
```