### 解题思路
直接遍历法

![image.png](https://pic.leetcode-cn.com/9c7b1ec62f485744af6b8ad249ee72f5859350678fede4ebca9393e11b3fd48f-image.png)



### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length() == 0 || S.length() < 2) {
            return S;
        }
        char ch = S.charAt(0);
        StringBuilder ans = new StringBuilder().append(ch);
        int num = 0;
        for(char c : S.toCharArray()) {
            if(ch == c){
                num ++;
            }else{
                ans.append(num);
                ch = c;
                ans.append(ch);
                num = 1;
            }

        }
        return ans.append(num).length() < S.length() ? ans.toString() : S;

    }
}
```