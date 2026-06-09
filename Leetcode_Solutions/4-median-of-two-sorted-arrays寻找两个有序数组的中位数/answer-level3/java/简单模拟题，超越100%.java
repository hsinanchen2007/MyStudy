class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int s1=0,s2=0;
        int k=(len1+len2)>>1;//取中间个数
        double m1=0,m2=0;
        if(len1 == 1 && len2 == 0)//特判
            return nums1[0];
        else if(len1 == 0 && len2 == 1)//特判
            return nums2[0];
        while(s1 < len1 || s2 <len2){
            k--;
            //如果两个数组都没有到头
            if(s1 != len1 && s2 != len2){
                //取小的
                if(nums1[s1] <= nums2[s2]){
                    if(k == 0)
                        m1 = nums1[s1];
                    s1++;
                }
                else{
                    if(k == 0)
                        m1 = nums2[s2];
                    s2++;
                }
            }
            else if(s1 != len1){//第一个数组空了，直接看第二个数组
                if(k == 0)
                    m1 = nums1[s1];
                s1++;
            }
            else{//同上
                if(k == 0)
                    m1 = nums2[s2];
                s2++;
            }
            if(k == 0){
                if(s1 != len1 && s2 != len2){
                    if(nums1[s1] <= nums2[s2])
                        m2 = nums1[s1];
                    else
                        m2 = nums2[s2];
                }
                else if(s1 != len1){
                    m2 = nums1[s1];
                }else{
                    m2 = nums2[s2];
                }
                if((len1 + len2)%2==0){//偶数取两个
                    return (m1+m2)/2;
                }
                else{//基数取两个
                    return m2;
                }
            }
        }
        return 0.0;
    }
}