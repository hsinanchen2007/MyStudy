```
        int result = 0;
        for (int i = 0; i < A.length; i++) {
            int iNum = A[i];
            for (int j = i + 1; j < A.length; j++) {
                int jNum = A[j];
                for (int k = j + 1; k < A.length; k++) {
                    if (iNum + jNum + A[k] == target) result++;
                }
            }
        }
        return result;
```
这个方法肯定是可以求正确答案的。但是题目说的超出部分处理怎么做？