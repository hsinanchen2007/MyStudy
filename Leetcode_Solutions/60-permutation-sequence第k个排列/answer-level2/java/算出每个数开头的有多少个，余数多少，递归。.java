### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder res = new StringBuilder();
        StringBuilder str = new StringBuilder();
        int average = 1;
        for (int i = 1; i <= n; i++) {
            str.append(i);
            average *= i;
        }
        for (int i = n - 1; i >= 0; i--) {
            average /= (i + 1); // 以每个数开头的字符串的数量，比如n=3,k=4  average=2,代表以1开头的有两个
            int index = k / average;// 以第几个数开头
            if (k % average == 0) { // 表示以2开头
                k = average;
            } else {  //如果k=5,则有余数，就是以3开头
                k = k % average;
                index++;
            }
            char c = str.charAt(index - 1);
            str.deleteCharAt(index - 1);
            res.append(c);
        }
        return res.toString();  
    }
}
```