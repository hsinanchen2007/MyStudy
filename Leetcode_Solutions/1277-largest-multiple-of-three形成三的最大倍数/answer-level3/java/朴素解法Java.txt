### 解题思路
被3除的余数可以是0 1 2，如果是0 ，那么直接求最大解即可。如果余数是1，那么我们可以通过减去一个余数是1的数或者减去两个余数是2的数；如果余数是2的情况同理。

### 代码

```java
class Solution {
    List<Integer> one = new ArrayList<>();  // 记录余数是1的数，记录两个即可
    List<Integer> two = new ArrayList<>();  // 记录余数是2的数，记录两个即可

    public String largestMultipleOfThree(int[] digits) {
        Arrays.sort(digits);
        int len = digits.length;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += digits[i];
            if (one.size() < 3 && digits[i] % 3 == 1) {
                one.add(i);
            } else if (two.size() < 3 && digits[i] % 3 == 2) {
                two.add(i);
            }
        }
        List<Integer> exclude = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        if (sum % 3 != 0) {
            if (sum % 3 == 1) {
                if (one.size() != 0) {
                    sum -= digits[one.get(0)];
                    exclude.add(one.get(0));
                } else {
                    if (two.size() == 2) {
                        sum -= (digits[two.get(0)] + digits[two.get(1)]);
                        exclude.add(two.get(0));
                        exclude.add(two.get(1));
                    } else {
                        return "";
                    }
                }
            } else {
                if (two.size() != 0) {
                    sum -= digits[two.get(0)];
                    exclude.add(two.get(0));
                } else {
                    if (one.size() == 2) {
                        sum -= (digits[one.get(0)] + digits[one.get(1)]);
                        exclude.add(one.get(0));
                        exclude.add(one.get(1));
                    } else {
                        return "";
                    }
                }
            }
        }
        if (sum % 3 == 0) {
            for (int i = len - 1; i >= 0; i--) {
                if (!exclude.contains(i))
                    sb.append(digits[i]);
            }
        }

        return sb.toString().length() == 0 ? "" : sb.toString().charAt(0) == '0' ? "0" : sb.toString();
    }
}
```