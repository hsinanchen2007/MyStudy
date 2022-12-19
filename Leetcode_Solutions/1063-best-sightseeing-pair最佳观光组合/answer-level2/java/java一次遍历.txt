若要求得对于A[i]而言的最大值，只需计算i-1位置从头到i-1时最大是多少（每经过一个减一,最大值有可能是自身），该值存为cur
而在A[i]处的最大值即是A[i] + cur - 1


```
 public int maxScoreSightseeingPair(int[] A) {
        if(A.length == 0 || A.length == 1) return 0; 
        int cur = A[0];
        int max = -1;
        for(int i = 1; i < A.length; i++){
            max = Math.max(max , cur - 1 + A[i]);
            cur = Math.max(cur - 1 , A[i]);
        }
        return max;

    }
```

