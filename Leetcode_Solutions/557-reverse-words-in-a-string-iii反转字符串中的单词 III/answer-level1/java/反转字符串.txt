### 解题思路
1.s为空时，返回null
2.s如果只包含空格时，返回字符串本身
3.分割原来的字符串，并且将每个被分割的字符串进行反转，最后使用StringBuilder来拼接字符串
4.这是一个比较愚蠢的解法

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if (s != null){
            String[] arr = s.split(" ");
            if (arr.length > 0){
                StringBuilder sb = new StringBuilder(s.length());
                for (int i = 0;i < arr.length;i++){
                    int len = arr[i].length();
                    char[] nElem = new char[len];
                    for (int k = 0;k < len;k++){
                        nElem[k] = arr[i].charAt(len - k - 1);
                    }
                    sb.append(new String(nElem,0,nElem.length));
                    if (i < (arr.length - 1)){
                        sb.append(" ");
                    }
                }
                return sb.toString();
            }else{
                return s;
            }
        }else{
            return null;
        }
    }
}
```