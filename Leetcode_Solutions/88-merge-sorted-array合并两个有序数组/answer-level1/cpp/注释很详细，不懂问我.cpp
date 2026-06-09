```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {

        //从前往后 很复杂
        //从后往前 很简单
        int length=m+n;        
        int i=m-1;//第一个数组的指针
        int j=n-1;//第二个数组的指针
        int id=length-1;//最后结果数组的指针
        while(i>=0&&j>=0)
        {
            if(nums1[i]>=nums2[j])  nums1[id--]=nums1[i--]; 
            else nums1[id--]=nums2[j--];
        }
        //因为上面的while跳出来的时候，有3种情况
        //1.两者都为0，说明结合完毕
        //2.数组nums2的j为0，说明数组2完全融入到数组nums1中，ok
        //3.数组nums1的i为0，说明数组nums1的数字都到了末尾，但是，数组nums2还有的未来的及赋值到nums1中，未完全完成融合
        //为了确保确保两个数组合并起来
        while(j>=0)
        {
            nums1[id--]=nums2[j--];
        }
    }
};
```
