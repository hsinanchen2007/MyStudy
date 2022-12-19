class Solution {
    public void duplicateZeros(int[] arr) {
        for(int i=0;i<arr.length;i++){
            if(arr[i]==0){      //判断是否为零
                for(int j=arr.length-1;j>i;j--){//若为零数据就从赋值为前一个数值
                    arr[j]=arr[j-1];     //到i为最后一个赋值，这样也复写了零，因为只有符合零才复写和后移
                }
                i++;//因为下一位复写了零，所以要跳过复写的这个数值。
            }
        }
    }
}