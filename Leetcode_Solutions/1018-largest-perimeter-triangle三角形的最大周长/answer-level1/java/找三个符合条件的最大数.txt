三角形最长边a<b+c
可以将数组排序，从大到小依次取三个数判断，若符合，则输出a+b+c，不符合则去除当前最大值，加入剩余数组中的最大值，继续判断。
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        for (int i = A.length-1; i >=2 ; i--) {
            if (A[i]<A[i-1]+A[i-2]){
                return A[i]+A[i-1]+A[i-2];
            }
        }
        return 0;
    }