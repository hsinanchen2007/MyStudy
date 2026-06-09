降序排列得到的数字，如果能被三整除，则为结果；如果不能，则减去最少的个数来保证结果的位数最大

如果结果mod 3 == 1，则需要从小到大遍历出第一个可以mod 3 = 1 的数字并去掉；如果找不到，则减去两个mod 3 = 2的数字。

如果结果mod 3 == 2，则需要从小到大遍历出第一个可以mod 3 = 2 的数字并去掉；如果找不到，则减去两个mod 3 = 1的数字。

```java
    public String largestMultipleOfThree(int[] digits) {
        Arrays.sort(digits);

        int sum = 0;
        for (int i = 0; i < digits.length; i ++) {
            sum += digits[i];
        }

        if (sum < 3) {
            for (int num : digits) {
                if (num == 0) {
                    return "0";
                }
            }

            return "";
        }

        StringBuilder ans = new StringBuilder();
        for (int i = digits.length - 1; i >= 0; i --) {
            ans.append(digits[i]);
        }

        if (sum % 3 == 0) {
            return ans.toString();
        }

        if (sum % 3 == 1) {
            getMod1(ans, digits);
        } else {
            getMod2(ans, digits);
        }

        return ans.toString();
    }

    private int[] getMod1(StringBuilder sb, int[] digits) {
        for (int i = 0; i < digits.length; i ++) {
            if (digits[i] % 3 == 1) {
                sb.deleteCharAt(digits.length - 1 - i);
                int[] newDigits = new int[digits.length - 1];
                for (int j = 0; j < i; j ++) {
                    newDigits[j] = digits[j];
                }

                for (int j = i+1; j < digits.length; j ++) {
                    newDigits[j-1] = digits[j];
                }

                return newDigits;
            }
        }

        digits = getMod2(sb, digits);
        return getMod2(sb, digits);
    }

    private int[] getMod2(StringBuilder sb, int[] digits) {
        for (int i = 0; i < digits.length; i ++) {
            if (digits[i] % 3 == 2) {
                sb.deleteCharAt(digits.length - 1 - i);
                int[] newDigits = new int[digits.length - 1];
                for (int j = 0; j < i; j ++) {
                    newDigits[j] = digits[j];
                }

                for (int j = i+1; j < digits.length; j ++) {
                    newDigits[j-1] = digits[j];
                }

                return newDigits;
            }
        }

        digits = getMod1(sb, digits);
        return getMod1(sb, digits);
    }
```
