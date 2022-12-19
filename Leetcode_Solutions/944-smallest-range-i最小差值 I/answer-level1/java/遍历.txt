根据题意，找出数组最大最小值，再以最大最小值差和2K比较即可
```
public int smallestRangeI(int[] A, int K) {
        int max = A[0], min = A[0];
        for (int a : A) {
            if (a > max) max = a;
            if (a < min) min = a;
        }
        return Math.max((max - min - 2 * K),0);
    }
```
