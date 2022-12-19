
```
public static int[] sortArrayByParity(int[] A) {
        int[] a = new int[A.length];
        int right = A.length - 1;
        int left = 0;
        for (int i = 0; i < A.length; i++) {
            if (A[i] % 2 == 0) {
                a[left] = A[i];
                left++;
            } else {
                a[right] = A[i];
                right--;
            }
        }
        return a;
    }
```
        