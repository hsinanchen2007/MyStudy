```
public void merge(int[] A, int m, int[] B, int n) {
        int len = A.length;
        int index = m;
        for(int i = 0; i < B.length; i++){
            A[index++] = B[i];
        }
        Arrays.sort(A);
    }
```
