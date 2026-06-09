方法一：
```
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        if(A.length < 2 || A.length> 20000 || A.length % 2 != 0) {
            return new int[0];
        }
        int[] B = new int[A.length];
        int oddCount = 0;       //奇数数量
        int evenCount = 0;      //偶数数量
        for(int i=0; i<A.length; i++) {
            if(A[i] <0 || A[i] > 1000) {
                return new int[0];
            }
            if(A[i] % 2 == 0) {
                B[2 * evenCount] = A[i];
                evenCount++;
            }else {
                B[2 * oddCount + 1] = A[i];
                oddCount++;
            }
        }
        return B;    
    }
}
```


方法二：参考官方思路自行写的方法，执行效率超慢
```
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        if(A.length < 2 || A.length> 20000 || A.length % 2 != 0) {
            return new int[0];
        }
        int temp;    //临时变量，替换值使用
        for(int i=0; i<A.length; i++) {
            if(A[i] <0 || A[i] > 1000) {
                return new int[0];
            }
            if(i % 2 == 0 && A[i] % 2 != 0) {
                for (int j = i + 1; j < A.length; j++) {
                    if (A[j] % 2 == 0) {
                        temp = A[j];
                        A[j] = A[i];
                        A[i] = temp;
                        break;
                    }
                }
            }
            if(i % 2 != 0 && A[i] % 2 == 0) {
                for(int j=i + 1; j<A.length; j++) {
                    if(A[j] % 2 != 0) {
                        temp = A[j];
                        A[j] = A[i];
                        A[i] = temp;
                        break;
                    }
                }
            }
        }
        return A;  
    }
}
```


