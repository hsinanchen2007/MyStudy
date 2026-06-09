### 解题思路
耗时0ms， 内存消耗37.3MB。双百。
建立大小为128的整型数组，每次读一个字符将字符转换为对应的数字，然后遍历一遍数组，回文需要满足数组中元素最多只有一个奇数。
### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        boolean flag = true;
        int intArrray[] = new int[128];
        for(int i = 0; i < 128; i++) {
            intArrray[i] = 0;
        }
        for(int i = 0; i < s.length(); i++) {
            intArrray[(int)s.charAt(i)]++;
        }
        int count = 0;
        for(int i = 0; i < 128; i++) {
            if (intArrray[i] % 2 != 0) {
                count++;
                if (count > 1) {
                    return false;
                }
            }
        }
        return true;
    }
}
```