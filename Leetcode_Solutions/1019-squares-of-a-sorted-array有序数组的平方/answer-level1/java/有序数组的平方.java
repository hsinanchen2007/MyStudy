### 解题思路
创建一个新的数组，用来存放数的平方
再对新数组内的数字进行排序

### 代码
```java
class Solution {
    public int[] sortedSquares(int[] A) {
        int n=A.length;
        int[] a=new int[n];
        for(int i=0;i<n;i++){
            a[i]=A[i]*A[i];
        }
        Arrays.sort(a);
        return a;
    }
}
```