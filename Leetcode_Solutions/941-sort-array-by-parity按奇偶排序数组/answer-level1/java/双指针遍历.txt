```
int left = 0, right = A.length - 1;
        while (left < right) {
            if (A[left] % 2 == 0) {
                left++;
                continue;
            }
            if (A[right] % 2 != 0) {
                right--;
                continue;
            }
            int tmp = A[left];
            A[left] = A[right];
            A[right] = tmp;
        }
        return A;
```
