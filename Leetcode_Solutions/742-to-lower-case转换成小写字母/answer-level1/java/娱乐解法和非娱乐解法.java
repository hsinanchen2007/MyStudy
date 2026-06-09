娱乐解法直接调用tolowerCase方法就好了

```
class Solution {
    public String toLowerCase(String str) {
        return str.toLowerCase();
    }
}
```
第二种解法遍历字符串判断当前字符是否在A到Z之间，如果在A到Z之间减去'A'-'a'的值就好了（不太记得是多少）
```
class Solution {
    public String toLowerCase(String str) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0 ;i<str.length();i++){
            if(str.charAt(i)>='A' && str.charAt(i) <='Z'){
                char temp = (char) (str.charAt(i)-('A'-'a'));
                sb.append(temp);
            }else {
                sb.append(str.charAt(i));
            }
        }
        return sb.toString();
    }
}
```
