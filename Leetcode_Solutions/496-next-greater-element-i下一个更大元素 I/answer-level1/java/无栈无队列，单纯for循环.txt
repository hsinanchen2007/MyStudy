单纯用for循环来实现，虽然复杂了点，但是思路比较简单。
```
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] list=new int[nums1.length];
        for(int i=0;i<(nums1.length);i++){
            int ll=loc(nums1[i],nums2);
            //如果已经到nums2的最后一个元素了，就不能用ll+1，不然会爆数据越界
            if(ll>=(nums2.length-1)){
                list[i]=-1;
            }else{
                int count=0;
                Boolean flag=false;
                //在nums2里找
                for(int j=(ll+1);j<nums2.length;j++){
                    if(nums2[j]>nums1[i]){
                        flag=true;
                        count=nums2[j];
                        break;
                    }
                }
                if(flag==true)
                    list[i]=count;
                else
                    list[i]=-1;
            }
        }
        return list;
    }
    //题目要求在对应nums2里元素之后找，所以先声明一个位置函数，用来找到nums1里元素对应在nums2里的位置。
    public int loc(int x, int[] nums){
        int res=0;
        for(int i=0;i<(nums.length);i++){
            if(nums[i]==x){
                res=i;
                break;
            }
        }
        return res;
    }
}
```
