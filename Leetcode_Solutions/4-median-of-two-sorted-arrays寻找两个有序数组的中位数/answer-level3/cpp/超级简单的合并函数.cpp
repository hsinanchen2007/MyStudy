执行结果：
通过  
显示详情  
执行用时 :16 ms, 在所有 C++ 提交中击败了92.38%的用户  
内存消耗 :10 MB, 在所有 C++ 提交中击败了28.09%的用户
```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a;
        a.resize(nums1.size() + nums2.size());
        //合并两个数组（两个数组分别一定要排好序）
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),a.begin());
        if(a.size()%2 == 0){
            int mid = a.size()/2;
            double m = (a[mid-1] + a[mid]) / 2.0;
            return m;
        }
        else{
            int mid = a.size()/2;
            return a[mid];
        }
    }
};
```