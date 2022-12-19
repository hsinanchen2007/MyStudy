### 解题思路
遍历字符串，相应的的计数器加1，并且如果遇到的不是L就让L字符的数量归零，这样可以保证只有连续的三个L才会退出循环

### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
        int a = 0;
        int l = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'P')
                l = 0;
            if(s.charAt(i) == 'A'){
                a++;
                l = 0;
            }  
            else if(s.charAt(i) == 'L')
                l++;
            if(a > 1 || l > 2)
                return false;
        }
        return true;
    }
}
```