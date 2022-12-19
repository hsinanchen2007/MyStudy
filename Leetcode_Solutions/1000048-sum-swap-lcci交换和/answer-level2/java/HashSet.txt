# 代码
```java
class Solution {
    public int[] findSwapValues(int[] array1, int[] array2) {
        int sum1 = 0, sum2 = 0;
        int len1 = array1.length, len2 = array2.length;
        HashSet<Integer> set1 = new HashSet<>(len1), set2 = new HashSet<>(len2);
        for (int num : array1) {
            sum1 += num;
            set1.add(num);
        }
        for (int num : array2) {
            sum2 += num;
            set2.add(num);
        }
        if ((sum1 + sum2) % 2 != 0) return new int[0];
        int avg = (sum1 + sum2) >> 1;
        int diff1 = sum1 - avg;
        if (diff1 < 0) {
            for (int num1 : set1)
                if (set2.contains(num1 - diff1))
                    return new int[]{num1, num1 - diff1};
        } else {
            for (int num2 : set2)
                if (set1.contains(num2 + diff1))
                    return new int[]{num2 + diff1, num2};
        }
        return new int[0];
    }
}
```
