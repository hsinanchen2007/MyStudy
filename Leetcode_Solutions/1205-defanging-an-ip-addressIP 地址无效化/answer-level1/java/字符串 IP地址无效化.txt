### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
String res="";
for(char a:address.toCharArray()){
    if(a=='.'){
        res+="[.]";
    }else{
        res+=a;
    }
}
return res;
    }
}
```