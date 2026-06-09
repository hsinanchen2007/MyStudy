### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String toHex(int num) {
        if (num == 0)
            return "0";

        StringBuilder ans = new StringBuilder();

        String[] pat = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f" };

        int bit = 0;
        while ((num >> bit) != 0 && bit < 32) {

            int n = 0;
            n += ((num >> bit) & 1);
            n += ((num >> bit + 1) & 1) << 1;
            n += ((num >> bit + 2) & 1) << 2;
            n += ((num >> bit + 3) & 1) << 3;

            ans.append(pat[n]);
            bit += 4;
        }


        return ans.reverse().toString();
    }
}
```