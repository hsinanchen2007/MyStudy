原数组和目标数组个数相同，目标数组个数的组成是一个A[0]*...A[n-1]的数，加上A[1] ~ A[n-1]中依次缺失一个数，剩余数的乘积。
以缺失数的下标为界，依次将下标的左侧和右侧的数分别作出乘积，就得到想要的数字。```
代码块
class Solution {
    public int[] constructArr(int[] a) {
        int[] res = new int[a.length];
        int temp = 1;
        int temp1 = 1;
        if(a.length != 0){
            for(int i =0;i<a.length;i++){
                res[i] = temp;
                temp *= a[i];
            }
            for(int j = a.length-1;j>=0;j--){
                res[j] = res[j] * temp1;
                temp1 *= a[j];
            }
        }
        return res;
    }
}
