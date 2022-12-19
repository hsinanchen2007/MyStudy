执行用时 :3 ms, 在所有Java提交中击败了97.69%的用户

内存消耗 :43.2 MB, 在所有Java提交中击败了78.77%的用户

```java
public int[] sortArrayByParity(int[] A) {
        int a[] = new int[A.length];
        int j = 0, k = A.length - 1;
        for (int i = 0; i < A.length; i ++){
            if(A[i] % 2 == 0){
                a[j++] = A[i];
            }else{
                a[k--] = A[i];
            }
        }
        return a;
    }
```