### 解题思路
报数，按照正常思路即可。
11 ==> 2个"1"，下一个即是 21
21 ==> 1个"2"，1个“1”，下一个即是1211
如此循环。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String res = "1";
        for (int i = 1; i < n; i++){
            res = next(res);
        }
        return res;
    }

    public String next(String num){
        if (num.equals("1")){
            return "11";
        }
        char previous = num.charAt(0);
        String res = "";
        int same_char = 1;
        for (int i = 1; i < num.length(); i++){
            char current = num.charAt(i);
            if (current == previous){
                same_char++;
            } else {
                res = res + same_char + previous;
                same_char = 1;
            }
            previous = current;
            
            if (i == num.length() - 1){
                res = res + same_char + current;
            }
        }

        return res;
    }
}
```