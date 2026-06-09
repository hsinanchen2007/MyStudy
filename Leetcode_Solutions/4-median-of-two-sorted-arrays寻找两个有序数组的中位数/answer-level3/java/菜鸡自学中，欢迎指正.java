### 解题思路
已知两个数组是有序的
两个数组从第一个数开始比较
小的index++再比
若比到了中间的一个或两个数
把它保存进链表里，好计算平均值
若index++到了边界，将边界值改为另一数组的最大值


### 代码

```java
class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int middle = (nums1.length+nums2.length)/2;
        List<Integer> mlist = new ArrayList<>();
        int count =1;
        int index1 = 0;
        int index2 = 0;
        double result = 0.0;
        //特例
        if(n1==0){
            if(n2%2==0){
                result = (nums2[n2/2-1]+nums2[n2/2])/2.0;
            }else
                result = nums2[(n2-1)/2];
            return result;
        }else if(n2==0){
            if(n1%2==0){
                result = (nums1[n1/2-1]+nums1[n1/2])/2.0;
            }else
                result = nums1[(n1-1)/2];
            return result;
        }
        while(count <= (middle+1)){
            if (nums1[index1] <= nums2[index2]) {
                getList(nums1, n1, n2, middle, mlist, count, index1);
                if(index1<n1-1){
                    index1++;
                }else{
                    nums1[index1] = nums2[n2-1];
                }
            }else{
                getList(nums2, n1, n2, middle, mlist, count, index2);
                if(index2<n2-1){
                    index2++;
                }else{
                    nums2[index2] = nums1[n1-1];
                }
            }
            count++;
        }
        double sum = 0.0;
        System.out.println(mlist);
        for(Integer num:mlist){
            sum = sum+num;
        }
        result = sum / mlist.size();
        return result;
    }

    private static void getList(int[] nums1, int n1, int n2, int middle, List<Integer> mlist, int count, int index1) {
        if((n1+n2)%2==0){
            if(count==middle || count==middle+1){
                mlist.add(nums1[index1]);
            }
        }else{
            if(count==middle+1){
                mlist.add(nums1[index1]);
            }
        }
    }
}
```