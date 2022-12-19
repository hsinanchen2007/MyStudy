
1. 先根据题意定义arr[0]=1,并定义因数 2、3、5对应的下标
2. 求出对应的下标乘 2、3、5最小的值放入数组里
3. 判断是否可以有自己乘得出最小的值，能就下标都加1
```
class Solution {
    //乘 2 或 3 或 5，之后比较取最小值。
    public int nthUglyNumber(int n) {
        if(n<1) {
            return 0;
        }
        int[] arr = new int[n];
        arr[0] =1;
        int num2 = 0;
        int num3 = 0;
        int num5 = 0;
        for(int i=1;i<n;i++) {
            //乘 2 或 3 或 5，之后比较取最小值。
            int min = Math.min(Math.min(arr[num2]*2,arr[num3]*3),arr[num5]*5);
            arr[i] = min;
            //如果等于则证明实现过，可以下标移动，2*3 3*2这个情况要注意都需要下标加1在if里判断
            if(arr[num2]*2==min) {
                num2++;
            }
            if(arr[num3]*3==min) {
                num3++;
            }
            if(arr[num5]*5==min) {
                num5++;
            }
        }
        return arr[n-1];
    }
}
```
