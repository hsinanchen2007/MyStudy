class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        // 思路
        // 1、数组只能指定位置加数，所以不知道长数组元素个数只能倒着加
        // 2、先把短的数组挨个取出来，倒着加到长数组里
        // 3、把长数组指针倒着移，因为长数组够大能放进去
        // 4、组合成一个数组后排序

        int j = 0;
        int k = 0;
        k = nums1.length;

        for(int i = 0; i < nums2.length; i++){
            j = nums2[i];
            nums1[k-1] = j;
            k--;
        }

        Arrays.sort(nums1);
    }
}