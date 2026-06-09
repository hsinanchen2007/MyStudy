### 解题思路
此处撰写解题思路
分奇数偶数两种情况
执行用时 :
4 ms
, 在所有 Java 提交中击败了
73.99%
的用户
内存消耗 :
37.5 MB
, 在所有 Java 提交中击败了
5.94%
的用户
### 代码

```java
class Solution {
    int res = 0;
    public int countSubstrings(String s) {
        for (int i = 0; i < s.length(); i++){
            //回文串分奇数和偶数
            count(s, i, i);//奇数
            count(s, i, i + 1);//偶数
        }
        return res;
    }
    private void count(String s, int left, int right){
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            res++;
            left--;
            right++;
        }
    }
}
```