### 解题思路
其实就是两层for循环遍历所有情况，按理说应该是O(n2)的复杂度，只不过根据两个相等的数或操作依然相等的原理，把后面很多不必要的或操作去掉了，这是剪枝法。
因为是数组的形式，所以用到了arraycopy方法，如果使用链表进行删除操作，性能应该会有提升，没试过，有兴趣的朋友可以试一下。

### 代码

```java
class Solution {
    public int subarrayBitwiseORs(int[] A) {
        Set<Integer> sum = new HashSet<>();
        int length = A.length;
        for (int value : A) {
            sum.add(value);
        }
        for (int i = 1; i < length; i++) {
            for (int j = 0; j < length - i; j++) {
                if (A[j] == A[j + 1]) {
                    System.arraycopy(A, j + 1, A, j, length - j - 1);
                    j--;
                    length--;
                    continue;
                }
                sum.add(A[j] |= A[j + 1]);
            }
        }
        return sum.size();
    }
}
```