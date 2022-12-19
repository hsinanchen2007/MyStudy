### 解题思路
核心就是一个比较器，根据两个字符串的两种不同拼接方法判断大小。

### 代码

```java
class Solution {

    public String largestNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        String[] strArr = new String[nums.length];
        int zeroCount = 0;
        for (int i = 0; i < nums.length; i++) {
            strArr[i] = String.valueOf(nums[i]);
            if (nums[i] == 0) {
                zeroCount++;
            }
        }
        if (zeroCount == nums.length) {
            return "0";
        }
        Arrays.sort(strArr, new NumComparator());
        StringBuilder stringBuilder = new StringBuilder();
        for (String str : strArr) {
            stringBuilder.append(str);
        }
        return stringBuilder.toString();
    }

    static class NumComparator implements Comparator<String> {

        @Override
        public int compare(String o1, String o2) {
            String str1 = o1 + o2;
            String str2 = o2 + o1;
            for (int i = 0; i < str1.length(); i++) {
                if (str1.charAt(i) < str2.charAt(i)) {
                    return 1;
                } else if (str1.charAt(i) > str2.charAt(i)) {
                    return -1;
                }
            }
            return 0;
        }
    }

}
```