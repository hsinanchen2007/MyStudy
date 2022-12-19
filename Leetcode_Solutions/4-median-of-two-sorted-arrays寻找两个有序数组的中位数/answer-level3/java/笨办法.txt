### 解题思路
此处撰写解题思路

感觉写的很烂还通过了
执行用时 :
3 ms
内存消耗 :
42.3 MB
的用户
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int size=nums1.length+nums2.length;
        int [] temp=new int[size];
        for(int i=0,j=0,z=0;i<size;i++){
            if(j>=nums1.length){
                temp[i]=nums2[z];
                z++;
            }else if(z>=nums2.length){
                temp[i]=nums1[j];
                j++;
            }else {
                if(nums1[j]<nums2[z]) {
                    temp[i]=nums1[j];
                    j++;
                }else{
                    temp[i]=nums2[z];
                    z++;
                }
            }
        }
        if(size%2==1)return temp[size/2];
        else return (temp[size/2]+temp[size/2-1])/2.0;
    }
}
```