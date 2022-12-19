还有一种方法，个人觉得在nums1比较长，nums2比较短的时候效率会比较好，当然还是不如官方的题解的第三种方法。

遍历nums1中的元素，每次都与nums2的第一个元素相比较，如果nums1中的元素比nums2中的第一个元素大，就将这两个元素交换，然后对nums2数组进行调整，使其仍满足有序。
```
class Solution {
public:
    void adjust(vector<int>& nums,int n){
        if(n<=1) return;
        
        if(nums[0]<=nums[1]) return ;
        int tmp=nums[0];
        int i,flag=1;
        for(i=1;i<n;i++){
            if(tmp>nums[i]){
                nums[i-1]=nums[i];

            }else{
                nums[i-1]=tmp;
                flag=0;
                break;
            }
        }
        if(i==n&&flag){
            nums[i-1]=tmp;
        }
    }
    void swap(int& a,int& b){
        int t=a;
        a=b;
        b=t;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m<=0&&n<=0) return;
        if(n<=0) return;
        if(m<=0)
        {
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }
            return;
        }
        int i;
        for(i=0;i<m;i++){
            if(nums1[i]>nums2[0]){
                swap(nums1[i],nums2[0]);
                adjust(nums2,n);
            }
        }
        for(int j=0;i<m+n&&j<n;i++,j++){
            nums1[i]=nums2[j];
        }
    }
};
```
