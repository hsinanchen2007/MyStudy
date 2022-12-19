# 方法一
没有什么是暴力不能解决的。如果有，那么就用HashSet空间换时间。时间空间复杂度O(n)
```
    public static int[] fairCandySwap(int[] A, int[] B) {
        int sumA = 0, sumB = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int i : A) sumA += i;
        for (int i : B) {
            sumB += i;
            set.add(i);
        }
        int sumAvg = (sumA + sumB) / 2;
        for (int i = 0; i < A.length; i++) {
            int another = sumAvg - sumA + A[i]; // sumA - A[i] + B中另一个数 == sumAvg
            if (set.contains(another)) {
                return new int[]{A[i], another};
            }
        }
        throw new IllegalArgumentException("don't have answer.");
    }
```

# 方法二
暴力，时间复杂度O(n^2)
```
    public static int[] fairCandySwap(int[] A, int[] B) {
        int lenA = A.length, lenB = B.length, sumA = 0, sumB = 0, sumAvg;
        for (int i : A) sumA += i;
        for (int i : B) sumB += i;
        sumAvg = (sumA + sumB) / 2;
        for (int i = 0; i < lenA; i++) {
            for (int j = 0; j < lenB; j++) {
                if (sumA - A[i] + B[j] == sumAvg) {
                    return new int[]{A[i], B[j]};
                }
            }
        }
        throw new IllegalArgumentException("don't have answer.");
    }
```
