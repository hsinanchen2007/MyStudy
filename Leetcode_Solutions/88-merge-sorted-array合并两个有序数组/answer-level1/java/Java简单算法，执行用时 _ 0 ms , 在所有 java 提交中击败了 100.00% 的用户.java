```
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        m -= 1;
        n -= 1;
        int point = n + m + 1;
        //从尾到头
        while(n >=0 && m >= 0){
            if(nums2[n] > nums1[m]){
                nums1[point] = nums2[n];
                n--;
            }else{
                nums1[point] = nums1[m];
                m--;
            }
            point--;
        }
        //数组2已经全部合并到数组1中，则直接结束
        if( n < 0)
            return;
        //将数组2剩下的数（比所有已经在数组1里面的值都小）合并到数组1
        while(n >= 0){
            nums1[point] = nums2[n];
            n--;
            point--;
        }
    }
}
```