太神奇了，从后往前插入，控制好判断条件，既节约空间又节省时间~~~
代码自己写的，但是从后往前插是看了其他人题解的标题突然想到的~
`class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m+n-1;i>=0;i--){
            if(n<1||m>=1&&nums1[m-1]>nums2[n-1])nums1[i]=nums1[--m];
            else nums1[i]=nums2[--n];
        }
    }
};`
