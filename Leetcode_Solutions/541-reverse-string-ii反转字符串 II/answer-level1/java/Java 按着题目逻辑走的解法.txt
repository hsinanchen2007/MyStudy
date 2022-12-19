### 解题思路
每次取字符串中的2k个字符，然后反转前面k个字符，再append后面k个不需要反转的字符。 如果最后长度不够2k了，就需要分情况讨论了
1ms, 40MB

### 代码

```java
class Solution {
    public String reverseStr(String s, int k) {
        int count = 0;
        StringBuilder sb = new StringBuilder();
        if(s.length() < k){
            StringBuilder tmp = new StringBuilder(s).reverse();
            return tmp.toString();
        }
        if(s.length() < (2 * k)){
            StringBuilder sb1 = new StringBuilder(s.substring(0,k)).reverse();
            return sb1.append(s.substring(k)).toString();
        }

        int start = 0, i = s.length();
        while (i >= (2 * k)){
            StringBuilder tmp = new StringBuilder(s.substring(start, start+k)).reverse();
            tmp.append(s.substring(start + k, start + (2 * k)));
            sb.append(tmp);
            start += (2 * k);
            i -= (2 * k);
        }
        if(i == 0)
            return sb.toString();
        else{
            //如果剩下的字符不够k,全部反转
            if(i < k) {
                StringBuilder tmp = new StringBuilder(s.substring(start)).reverse();
                sb.append(tmp);
            }
            //剩下的字符大于k，反转k个，再依次添加最后的
            else {
                StringBuilder tmp = new StringBuilder(s.substring(start, start + k)).reverse();
                sb.append(tmp);
                sb.append(s.substring(start+k));
            }
        }
        return sb.toString(); 
    }
}
```