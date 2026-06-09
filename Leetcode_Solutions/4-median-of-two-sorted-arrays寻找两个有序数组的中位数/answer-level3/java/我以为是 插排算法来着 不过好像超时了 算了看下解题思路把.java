### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        //就是一个排序算法 折中插入排序算法
        int[] newArray=new int[nums1.length+nums2.length];
        for(int i=0;i<nums1.length;i++){
            newArray[i]=nums1[i];
        }
        for(int i=nums1.length;i<nums2.length+nums1.length;i++){
            newArray[i]=nums2[i-nums1.length];
        }
        //进行排序
        //默认是前 i （i>0）个元素已经完成了排序 对 i>=1 个元素进行排序
        for(int i=1;i<newArray.length;i++){
            int low =0;
            int high=i-1;
            //目标元素
            int target=newArray[i];
            //前面元素的 中间元素
            while(low<=high){
                int mid=newArray[(low+high)/2];
                if(target>mid){
                    low=(low+high)/2+1;
                }else{
                    high=(low+high)/2-1;
                }
            }
            //进行数据平移
            for(int j=i;j>low;j--){
                newArray[j]=newArray[j-1];
            }
            newArray[low]=target;
        }
        //进行中位数计算
        if(newArray.length%2==0){
            //偶数
            return ((double)newArray[newArray.length/2-1]+(double)newArray[newArray.length/2])/2;
        }else{
            return newArray[newArray.length/2];
        }

    }
}
```