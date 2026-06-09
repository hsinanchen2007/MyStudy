**思路**
A组：数组中重复的元素组成的数组。比如[1, 2, 1, 3, 2, 2]中，A=[1, 2, 2]
B组：从数组第一个元素开始依次往后找在数组中没有出现过的数，直到找够A组的元素个数
则，结果 = B组元素的总和 - A组元素的总和

**代码**
```
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A == null || A.length == 0) {
                return 0;
            }
            // 先排序
            Arrays.sort(A);
            int i = 0;
            int totalA = 0;
            int totalB = 0;
            int countA = 0;
            int countB = 0;
            while(i < A.length) {
                if(i + 1 < A.length) {
                    if(A[i] == A[i + 1]) {
                        totalA += A[i];
                        countA ++;
                    }else{
                        if(A[i + 1] - 1 > A[i] && countB < countA) {
                            if(A[i + 1] - 1 == A[i] + 1) {
                                totalB += A[i] + 1;
                                countB ++;
                            }else{
                                int num = Math.min(countA - countB, A[i + 1] - A[i] - 1);
                                int begin = A[i] + 1;
                                int end = begin + num - 1;
                                totalB += (begin + end) * num / 2;
                                countB += num;
                            }
                        }
                    }
                }
                i++;
            }
            if(countB < countA) {
                int begin = A[A.length - 1] + 1;
                int end = begin + (countA - countB) - 1;
                totalB += (begin + end) * (countA - countB) / 2;
            }
            return totalB - totalA;
    }
}
```
