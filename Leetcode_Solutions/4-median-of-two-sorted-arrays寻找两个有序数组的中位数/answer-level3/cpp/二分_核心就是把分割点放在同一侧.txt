```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        if (len1>len2) {//统一考虑短数组
            swap(nums1,nums2);
            swap(len1,len2);
        }
        int k=(len1+len2+1)/2;//均分数组长度，用来控制另一个数组分割点位置
        int left=0,right=len1;//对短数组进行二分查找全局中位点
        int m1,m2;
        double c1,c2;
        while(left<right){
            m1=(right+left)/2;//表示m1左边有m1个元素
            m2=k-m1;//表示m2左边有m2个元素，全局中位点左边元素个数是总数的一半
            //由于四个子数组要保证能组成总数组中位点的左右部分
            //因此，必须保证短数组左边子数组最大值，要大于长数组的分割左邻点
            if(nums1[m1]<nums2[m2-1])
                left=m1+1;
            else
                right=m1;
        }
        m1=(left+right)/2;
        m2=k-m1;
        c1=max( (m1>0)?nums1[m1-1]:INT_MIN,
            (m2>0)?nums2[m2-1]:INT_MIN );
        if((len1+len2)%2==1) return c1;
        c2=min((m1<len1)?nums1[m1]:INT_MAX,
            (m2<len2)?nums2[m2]:INT_MAX);
        return (c1+c2)/2;
    }
};
```
