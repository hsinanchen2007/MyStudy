### 解题思路

- 循环遍历数组
注意：总和为0的话，可以大于三段。

- 双指针
一个指向尾，一个指向头，分别向中间逼近。如果A(0) + ... + A(i) == A(j) + A(length)，返回true。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
        }
        if (sum % 3 == 0) {
            int splitNum = sum / 3;
            int tmp = 0;
            List<Integer> indexs = new ArrayList<>();
            for (int i = 0; i < A.length; i++) {
                tmp += A[i]; 
                if (tmp == splitNum) {
                    indexs.add(i);
                    tmp = 0;
                }
            }
            return indexs.size() == 3 || (sum == 0 && indexs.size() >= 3);
        }
        return false;
    }
}
```