### 解题思路
可以知道，对于一个数组，经过move操作然后再排序后，数组会唯一对应一个分段的、连续的数组，所以对哪个重复出现的数字进行move操作、或者进行多少次move操作都是不重要的，只要move操作后结果数组一致就是OK的。因为排序的结果数组会是分段连续的，所以我们在遍历排序好的数组A时可以设置一个`cur`变量，`cur`变量是下一个允许的唯一的数字，任何小于`cur`的变量都需要进行`(cur - A[i])`次move操作，若`cur`大于等于`A[i]`，则说明数组分段开始，需要更新`cur`为`A[i] + 1`。

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A.length == 0)
            return 0;
        int ans = 0, cur;
        Arrays.sort(A);
        cur = A[0] + 1;
        for(int i = 1; i < A.length; i++){
            if(A[i] < cur){
                ans += cur - A[i];
                cur++;
            }else{
                cur = A[i] + 1;
            }
        }
        return ans;
    }
}
```