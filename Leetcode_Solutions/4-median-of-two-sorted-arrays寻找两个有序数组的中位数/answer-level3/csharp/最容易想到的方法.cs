将两个数组合并成一个数组，然后对新合成的数组进行排序。
再判断新数组的长度是奇数还是偶数，进行结果的输出整理。


代码如下：

public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
    int[] nums = new int[nums1.Length + nums2.Length];
    nums1.CopyTo(nums,0);
    nums2.CopyTo(nums,nums1.Length);
    double re;
    Sort(nums);
    if(nums.Length % 2 == 0){
    re = (double)((nums[nums.Length/2-1]+nums[nums.Length/2]))/2;
    }
    else
        re = nums[nums.Length/2];
    return re;
}
public void Sort(int[] arr){
    for(int j=1;j<arr.Length;j++){
        for(int i=0;i<arr.Length-j;i++){ 
            if(arr[i]>arr[i+1]){ 
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}