### 解题思路
1. new 一个26个长的int数组, 讲所有字符放入数组中
2. 找出数量最多的字符
3. 将最多的字符放在偶数为
4. 将其与字符补位在偶数位后,在补齐所有奇数位
5. 输出结果

### 代码

```java
class Solution {
     public String reorganizeString(String S) {
        int[] arr = new int[26];
        char[] chars = S.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            arr[chars[i] - 'a'] ++;
        }
        // 找出最多数量的字符在arr中的索引
        int index = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > arr[index]) {
                index = i;
            }
        }
        int maxNum = arr[index];
        if (S.length() % 2 == 0 && maxNum > S.length() / 2) {
            return "";
        }
        if (S.length() % 2 != 0 && maxNum > S.length() / 2 + 1) {
            return "";
        }
        // 可以输出的话,在偶数索引位置先设置最多数量的字符
        char[] newChar = new char[chars.length];
        int evenIndex = 0;
        while (arr[index] > 0) {
            newChar[evenIndex] = (char) (index + 'a');
            evenIndex += 2;
            arr[index]--;
        }
        // 在将其与字符添加到chars数组中
        int oddIndex = 1;
        for (int i = 0; i < arr.length; i++) {
            while (arr[i] > 0) {
                if (evenIndex < newChar.length) {
                    newChar[evenIndex] = (char) (i + 'a');
                    evenIndex += 2;
                }else {
                    newChar[oddIndex] = (char) (i + 'a');
                    oddIndex += 2;
                }
                arr[i]--;
            }
        }

        return new String(newChar);
    }
}
```