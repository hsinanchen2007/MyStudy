### 解题思路
判断长度差别是否满足一位以内，超过一位返回false。对比两个字符串通用下标的字符是否相同，第一次出现字符不同采取相应措施，第二次出现则返回false：
- 如果a、b字符串一样长，则第一次碰到字符不同的时候跳过
- 如果a、b字符串不一样长，则第一次碰到字符不同的时候长的字符串的下标前进一位以后再比较

### 代码

```java
class Solution {
public boolean oneEditAway(String first, String second) {
        //判断长度差别是否满足一位以内
        int a=first.length()-second.length();
        if (a>1||a<-1){
            return false;
        }
        char[] chars1 = first.toCharArray();
        char[] chars2 = second.toCharArray();
        //只能跳过一次
        boolean hasContinue=false;
        for (int i = 0,j=0; i < chars1.length&&j<chars2.length; i++,j++) {
            if (chars1[i]==chars2[j]){
                continue;
            }else if(hasContinue){
                return false;
            }
            if (a==1){
                j--;
            }else if(a==-1){
                i--;
            }
            hasContinue=true;
        }
        return true;
    }
}
```