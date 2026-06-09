### 解题思路


### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        List<Integer> arrayJi = new ArrayList<>();
        List<Integer> arrayOu = new ArrayList<>();
        for (int a : A) {
            if (a % 2 == 0) {
                arrayOu.add(a);
            } else {
                arrayJi.add(a);
            }
        }

        for (int i = 0; i < A.length; i += 2) {
            A[i] = arrayOu.get(i / 2);
        }
        for (int i = 1; i < A.length; i += 2) {
            A[i] = arrayJi.get(i / 2);
        }
        return A;
    }
}
```