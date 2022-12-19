### 解题思路
因为move只能做增1操作，所以对数组排序后如果出现重复元素是对相邻重复元素的后者进行move操作，并且move操作后不能比后面的元素大否则后面的元素仍然需要做move操作。

在做move操作时可以记录一个步长，而不是每次+1，这样可以减少计算量。

### 代码

```java
class Solution {
    private int count=0;
    public int minIncrementForUnique(int[] A) {
        if(A==null||A.length==0){
            return 0;
        }
        Arrays.sort(A);
        int curMin = A[0];//记录下一次比较时的最小值
        int m = 0;//记录当前一次需要做的move操作的最少次数
        for(int i = 0; i < A.length - 1; i++){
            if(curMin >= A[i+1]){//出现了后面元素比前面的大，说明是前面元素做move操作导致的，后面的元素仍需要做move操作
                m = curMin - A[i+1] + 1;
                A[i+1] += m;
                this.count += m;
            }
            curMin = A[i+1];//下一个元素的值为下一次比较的最小值
        }
        return this.count;
    }
}
```