执行用时 : 53 ms , 在所有 Java 提交中击败了 22.81% 的用户
内存消耗 : 54.4 MB , 在所有 Java 提交中击败了 100.00% 的用户



```
class Solution {
    int[] aux;
    public int reversePairs(int[] nums) {
        if(nums.length==0) return 0;
        aux = new int[nums.length];
        int n =0 ;
        for(int sz = 1; sz<nums.length; sz+=sz)
            for(int lo=0; lo<nums.length-sz; lo+=sz+sz)
                n+=merge(nums, lo, lo+sz-1, Math.min(lo+sz+sz-1, nums.length-1));

        return n;
    }   

    public int merge(int[] a, int lo, int mid, int hi){
        int i=mid, j=hi;
        int count = 0;
        for(int k=lo; k<=hi; k++) aux[k] = a[k];
        // System.out.println(Arrays.toString(aux));
        for(int k=hi; k>=lo; k--){
            if(i<lo)             a[k] = aux[j--]; // 边界
            else if(j<mid+1)    a[k] = aux[i--]; // 边界
            else if( aux[i]>aux[j] ){
                                count += j - (mid+1)+1;
                                a[k] = aux[i--]; }
            else               a[k] = aux[j--];
            
        }
        return count;
    }
}
```
