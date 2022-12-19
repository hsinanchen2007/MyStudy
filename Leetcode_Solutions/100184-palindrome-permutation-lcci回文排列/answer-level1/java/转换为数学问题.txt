### 解题思路
如果字符串的长度的为奇数，那么在字符串中必须有1个出现次数为奇数的字符；
如果字符串的长度的为偶数，那么在字符穿中不能出现存在次数为奇数的字符。

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        int[] nums = new int[arr[arr.length - 1] + 1];
        int odds = 0;
        int evens = 0;
        for (char c : arr) {
            nums[c]++;
        }
        for (int n : nums) {
            if (n != 0) {
                if (n % 2 == 0) {
                    evens++;
                } else {
                    odds++;
                }
            }
        }
        return s.length() % 2 == 0 ? odds == 0 : odds == 1;
    }
}
```