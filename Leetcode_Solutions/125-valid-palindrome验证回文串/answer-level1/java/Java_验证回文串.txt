### 解题思路
1. 先过滤掉非字母数字，考虑到删除无效字符很麻烦，正难则反，不如将有效字符存入StringBuilder中！
2. 再用首尾指针判断StringBuilder是否是回文串。

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        int length=s.length();
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<length;i++){
            char ch=s.charAt(i);
            if(ch>='A'&&ch<='Z'){
                ch+=32;
            }
            if(ch>='a'&&ch<='z'||ch>='0'&&ch<='9'){
                sb.append(ch);
            }
        }
        for(int i=0,j=sb.length()-1;i<j;i++,j--){
            if(sb.charAt(i)!=sb.charAt(j))
                return false;
        }
        return true;
    }
}
```