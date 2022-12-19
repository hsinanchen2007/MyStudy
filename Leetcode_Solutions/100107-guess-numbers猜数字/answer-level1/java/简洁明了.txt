![火狐截图_2019-09-26T07-45-44.999Z.png](https://pic.leetcode-cn.com/95fa7e3547a90ed5754471f28db5589c92c06cbfd299f36b19e49a8bffce48e2-%E7%81%AB%E7%8B%90%E6%88%AA%E5%9B%BE_2019-09-26T07-45-44.999Z.png)

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int count = 0;
        for (int i = 0; i < 3; i++)
            if (guess[i] == answer[i])
                count++;
        return count;
    }
}

```
