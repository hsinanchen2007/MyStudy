### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int [] count = new int[128];
        char [] cc = s.toCharArray();
        //统计数目
        for (char c:cc)
            count[c]++;
        //从每一位统计最大偶数，看是否有奇数
        int total = 0;
        boolean oddExist = false;
        for (int i = 0;i<128;i++){
            if (count[i] > 0){
                total += count[i] / 2 * 2;
                oddExist |= (count[i] & 1) == 1;
            }
        }
        //如果有奇数，可以放中间
        if (oddExist)
            return total + 1;
        return total;
    }
}
```