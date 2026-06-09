
题解：分析题目可以知道我们取得数组中的最大数大于等于次最大数，然后返回数组中最大数的下标，如果条件不满足返回-1；
我用的是暴力解决法，耗时较大。


```
public int dominantIndex(int[] nums) {
        int n = nums.length+1; //初始数组+1 避免数组越界（不加一数组会越过下标界限）
        int[] nums_copy = new int[n];
        System.arraycopy(nums,0,nums_copy,0,n-1);
        Arrays.sort(nums_copy);
        if (nums_copy[n-1]>=(2*nums_copy[n-2])){
            for (int i = 0; i <nums.length ; i++) {
                if (nums[i]==nums_copy[n-1]){
                    return i;
                }
            }
        }
        return -1;
    }
```
