### 解题思路
一般的解法，首先计算每个数的平方，存放到新的数组中，接着对该数组进行冒泡排序即可

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        int[] arr = new int[A.length];
        for(int i = 0;i<A.length;i++) {
            arr[i] = A[i]*A[i];
        }
        for(int i = 0;i<arr.length-1;i++) {
            for(int j = i+1;j<arr.length;j++) {
                if(arr[i]>arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr;
    }
}
```