1. Java方法一（遍历平方再排序）
```
class Solution {
    public int[] sortedSquares(int[] A) {
        int[] result = new int[A.length];
        for(int i = 0; i < A.length; i++) {
            result[i] = A[i] * A[i];
        }
        Arrays.sort(result);
        return result;
    }
}
```

2. Java方法二（双指针）
```
class Solution {
    public int[] sortedSquares(int[] A) {
        int l = A.length;
        int j = 0;
        while(j < l && A[j] < 0) {
            j++;
        }
        int i = j - 1;
        int[] result = new int[l];
        int index = 0;
        while(i >= 0 && j < l) {
            if(A[i] * A[i] < A[j] * A[j]) {
                result[index++] = A[i] * A[i];
                i--;
            } else {
                result[index++] = A[j] * A[j];
                j++;
            }
        }
        while(i >= 0) {
            result[index++] = A[i] * A[i];
            i--;
        }
        while(j < l) {
            result[index++] = A[j] * A[j];
           j++;
        }
        return result; 
    }
}
```

3. JS方法（先map再sort）
```
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
    return A.map(pow).sort(function(x, y) {
        if(x > y) {
            return 1;
        }
        if(x < y) {
            return -1;
        }
        return 0;
    });
};
function pow(x) {
    return x * x;
}
```
