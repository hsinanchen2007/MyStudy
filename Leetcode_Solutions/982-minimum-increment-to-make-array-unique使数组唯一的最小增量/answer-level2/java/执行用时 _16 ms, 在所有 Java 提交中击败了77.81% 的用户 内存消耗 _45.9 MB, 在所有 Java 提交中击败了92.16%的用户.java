### 解题思路
此处撰写解题思路
 先排序，然后判断相邻两个元素，后一个小于前一个，则使后一个+1，记录次数，判断是否唯一递增。

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int count =0;
        for(int i=1;i < A.length;i++){
            if(A[i] <= A[i-1]){
                int temp = A[i];
                A[i] = A[i-1]+1;
                count += A[i] -temp;
            }
        }
        return count;
    }
}
```