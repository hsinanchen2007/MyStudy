### 解题思路
写了点文字，但是不会描述又删掉了，应该能看懂👀
公式(a - b) * 2 = sum1 - sum2;

### 代码

```java
class Solution {
    public int[] findSwapValues(int[] array1, int[] array2) {
        int sum1 = 0;
        int sum2 = 0;
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for (int a1 : array1) {
            set1.add(a1);
            sum1 += a1;
        }
        for (int a2 : array2) {
            set2.add(a2);
            sum2 += a2;
        }
        if (((sum1 + sum2) & 1) == 1) 
            return new int[0];
        //看了别人的才发现自己这一步真的有点蠢。。。
        //直接减就可以了
        int target = Math.abs(sum1 - sum2);
        if (sum1 > sum2) {
            for (Integer i : set1) {
                if (set2.contains(i - target / 2)){
                    return new int[]{i, i - target / 2};
                }
            }
        } else {
            for (Integer i : set2) {
                if (set1.contains(i - target / 2)){
                    return new int[]{i - target / 2, i};
                }
            }
        }
        return new int[0];
    }
}
```
### 时间复杂度O(Math.max(array1.length, array2.length))