此题可与第31题[https://leetcode-cn.com/problems/next-permutation/]()寻找下一个排列联系起来
具体思路可以看第31题的解，此题只是重复调用第31题的方法而已
我们知道了1234...n的排列，就可以找到它的下一个排列，要求第N个，就调用n-1次方法即可
主要是思路的转换，无脑回溯求出全部排列，再求第n个，容易超时
时间复杂度0(nk)
```
class Solution {
    public String getPermutation(int n, int k) {
        int[] arr=new int[n];
        for(int i=0;i<arr.length;i++){
            arr[i]=i+1;
        }
        for(int i=1;i<k;i++){
            findnext(arr);
        }
        StringBuilder sb=new StringBuilder();
        for(int i:arr){
            sb.append(i);
        }
        return sb.toString();
    }
 public void findnext(int[] arr){
        int i=arr.length-1;
        while(arr[i]<arr[i-1]){
            i--;
        }
        for(int j=arr.length-1;j>=i;j--){
            if(arr[j]>arr[i-1]){
                swap(arr,i-1,j);
                break;
            }
        }
        int l=i;
        int r=arr.length-1;
        while(l<r){
            swap(arr,l,r);
            l++;
            r--;
        }
    }
       public void swap(int[] arr,int i,int j){
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
}
```

