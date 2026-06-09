### 解题思路
从中间劈开，要么是分三种情况，向上找，向下找，和在平级找。然后将左边对称过来到右边。
比如145这个数，中间劈，劈点是4
向上就让4变成5，得到了155，然后对称过来得到151.
平级找就直接对称过来得到141.
向下找就让4变成3，得到了135，对称过来，得到131.
然后比较131和141还有151，谁距离原来的值145最近，那么结果就是谁。

这里面比较坑的情况就是不能自己找到自己，所以要判断下，如果结果是自己，就不行啦！
还有一个比较坑的就是，输入值为11的时候，这时候向下找找到的是1，所以凡是涉及到降位的，比如11降下来是9，100降下来是99.都要做下判断的。

### 代码

```java
class Solution {

    public String nearestPalindromic(String n) {
        long value = Long.parseLong(n);
        int M = n.length() / 2;
        String result = "";
        String add = String.valueOf(value + (long) Math.pow(10, M));
        long addValue = Long.parseLong(buildString(add.toCharArray()));

        String sub = String.valueOf(value - (long) Math.pow(10, M));
        long subValue = Long.parseLong(buildString(sub.toCharArray()));

        // 考虑降位
        if (n.length() > 1) {
            long devValue = Long.parseLong("9".repeat(n.length() - 1));
            if (subValue == value) {
                subValue = devValue;
            }

            if (Math.abs(value - subValue) > Math.abs(value - devValue)) {
                subValue = devValue;
            }
        }

        long middleValue = Long.parseLong(buildString(n.toCharArray()));


        long addMin = (long) Math.abs(value - addValue);
        if (addMin == 0) {
            addMin = Integer.MAX_VALUE;
        }

        long middleMin = (long) Math.abs(value - middleValue);
        if (middleMin == 0) {
            middleMin = Integer.MAX_VALUE;
        }

        long subMin = (long) Math.abs(value - subValue);
        if (subMin == 0) {
            subMin = Integer.MAX_VALUE;
        }

        long min = Math.min(addMin, subMin);
        min = Math.min(min, middleMin);
        if (min == addMin) {
            result = String.valueOf(addValue);
        }
        if (min == middleMin) {
            result = String.valueOf(middleValue);
        }
        if (min == subMin) {
            result = String.valueOf(subValue);
        }
        return result;
    }

    public String buildString(char[] chars) {
        int M = (chars.length + 1) / 2;
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < M; i++) {
            stringBuilder.append(chars[i]);
        }
        for (int i = 0; i < chars.length - M; i++) {
            stringBuilder.append(chars[chars.length - M - i - 1]);
        }
        return stringBuilder.toString();
    }

//    public static void main(String[] args) {
//        Solution solution = new Solution();
//        System.out.println(solution.nearestPalindromic("807045053224792883"));
//    }
}
```