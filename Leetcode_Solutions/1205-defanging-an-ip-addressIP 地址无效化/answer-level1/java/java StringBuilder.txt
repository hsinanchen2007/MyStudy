### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        StringBuilder sb = new StringBuilder();
        for( char c : address.toCharArray()){
            if(c != '.'){
                sb.append(c);
            }else {
                sb.append("[.]");
            }
        }
        return sb.toString();
    }
}
```