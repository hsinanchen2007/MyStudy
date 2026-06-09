### 解题思路
把输入的数字转成字符串，分割成数组，判断第一个和倒数第一个是否相等，如果是就判断第二个和倒数第二个是否相等，如果不是直接返回false,循环结束说明数字是回文，返回true

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        String[] str = (x+"").split("");
        int l=str.length;
        int n=l/2;
        for(int i=0;i<n;i++){
            if(!str[i].equals(str[l-1-i])){
                return false;
            }
        }
        return true;
    }
}
```