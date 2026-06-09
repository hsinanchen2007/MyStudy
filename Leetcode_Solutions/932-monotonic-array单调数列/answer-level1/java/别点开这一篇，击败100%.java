### 解题思路
先创建两个数up 和 down，分别记录元素i与元素i-1大小的情况

如果是单调上升的话，只会有一个数会被增加（相等情况不做记录）。


还有另一个想法是，先排序，然后对比元素组和排序后的数组是否相等，但看起来时间开销会比较大。

### 代码

```java

class Solution {
    public boolean isMonotonic(int[] A) {
        int up = 0, down = 0;

        for(int i = 1; i < A.length; i++){
            if(A[i - 1] > A[i]){
                down++;
            }else if(A[i - 1] < A[i]){
                up++;
            }

            if(down > 0 && up > 0) return false;
        }
        return true;
    }
}
```