### 解题思路
字符串公约数对应的长度也是字符串长度的公约数。因此可以先求两个字符串长度的公共公约数列表并按从大到小排序。再遍历公共公约数，检查对应的字符串是否符合两个字符串的公共公约数，是的话遍历结束（因为是从大到小检查）。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        return getCommonDivisor(str1, str2);
    }

    /**
     * get common string divisor of two String
     * @param str1
     * @param str2
     * @return
     */
    public String getCommonDivisor(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        SortedSet<Integer> divisor1 = getDivisors(len1);
        SortedSet<Integer> divisor2 = getDivisors(len2);
        SortedSet<Integer> intersection = getCommonDivisors(divisor1, divisor2);

        for(Integer num : intersection) {
            String substr = str1.substring(0, num);
            if(isStrDivisor(str1, substr) && isStrDivisor(str2, substr)){
                return substr;
            }
        }

        return "";
    }

    /**
     * check if substr is String divisor of str
     * @param str
     * @param substr
     * @return
     */
    public boolean isStrDivisor(String str, String substr) {
        int len1 = str.length();
        int len2 = substr.length();
        if(len1 % len2 !=0) {
            return false;
        }


        int repeat = len1/len2;
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<repeat; i++) {
            sb.append(substr);
        }

        return str.equals(sb.toString());
    }

    /**
     * get divisor list of number
     * @param number
     * @return
     */
    public SortedSet<Integer> getDivisors(int number) {
        SortedSet<Integer> divisors = new TreeSet<>();

        for(int i=1; i<Math.sqrt(number)+1; i++) {
            if(i * number/i == number) {
                divisors.add(i);
                divisors.add(number/i);
            }
        }

        return divisors;
    }

    /**
     * get common divisor list of two numbers in descend order
     * @param set1
     * @param set2
     * @return
     */
    public SortedSet<Integer> getCommonDivisors(SortedSet<Integer> set1, SortedSet<Integer> set2) {
        SortedSet<Integer> intersection = new TreeSet<>(Collections.reverseOrder());
        intersection.addAll(set1);
        intersection.retainAll(set2);

        return intersection;
    }
}
```