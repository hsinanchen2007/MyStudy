### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
int m=A.length;
        int n=B.length;
        if(m<n){
            //保证A数组大于B数组
            return findMedianSortedArrays(B,A);
        }
        //设置对于B数组分格线的最大最小位置
        int start=0,end=n;
        while (start<=end){
            //B数组左边的数量
            int i=(start+end)/2;
            //A数组左边的数量
            //保证总体在经过i,j两条线分割后左右两部分数量相等
            //如果数组总数量是奇数的话，保证左边+1==右边
            //i+j=m-i+n-j偶数
            //i+j+1=m-i+n-j-x奇数
            int j=(m+n+1)/2-i;
            if(j!=0 && i!=n && A[j-1]>B[i]){
                //j的位置大了，需要减小j，即扩大i,增加start
                start=i+1;
            }else if(i!=0 && j!=m && B[i-1]>A[j]){
                //i的位置大了，需要减少i，即减少end
                end=i-1;
            }else{
                int maxLeft=0;
                if(i==0){
                    maxLeft=A[j-1];
                }else if(j==0){
                    maxLeft=B[i-1];
                }else{
                    maxLeft=Math.max(A[j-1],B[i-1]);
                }
                if(((m+n)%2==1)){
                    return maxLeft;
                }
                int minRight=0;
                if(i==n){
                    minRight=A[j];
                }else if(j==m){
                    minRight=B[i];
                }else{
                    minRight=Math.min(A[j],B[i]);
                }
                return (maxLeft+minRight)/2.0;
            }
        }
        return 0.0;
    }
}
```