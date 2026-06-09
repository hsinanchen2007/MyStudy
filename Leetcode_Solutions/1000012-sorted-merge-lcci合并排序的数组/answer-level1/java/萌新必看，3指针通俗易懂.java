### 解题思路
这题的测试用例中，A.B都是排好序的，最简单就是把B先加到B后面，然后直接sort（A）。
定义一个指针在B的尾部j = n - 1，一个在A的尾部 i = m - 1，一个在有数值A的尾部 k = m + n - 1;
然后让k指针往前滑，比较 A[i] 与 B[j] 的值，把大的加入到A数组尾部，A[k] = max(A[i],B[j])。
当j滑动到0时，i没到0，就直接输出A，因为剩的都是A中小的数，且已经有序。
j还没得-1，说明B还有一些没放入，A中空余的也正好是j+1个元素，从头插进去就行。A[j] = B[j];

### 代码

```java
class Solution {
public void merge(int[] A, int m, int[] B, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i > -1 && j > -1){
            if(A[i] <= B[j]){
                A[k] = B[j]; j--;
            }
            else{
                A[k] = A[i]; i--;
            }
            k--;
        }
        if(j >= 0){
            for(i = 0; i <= j; i++)
                A[i] = B[i];
        } 
    }
}
```