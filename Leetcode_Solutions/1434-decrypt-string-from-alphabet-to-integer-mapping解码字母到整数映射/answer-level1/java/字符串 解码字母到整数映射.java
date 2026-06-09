### 解题思路
'0'对应的值为48
### 代码

```java
class Solution {
    public String freqAlphabets(String s) {
String res=new String();

for(int index=0;index<s.length();index++){
    if(index<s.length()-2){
        if(s.charAt(index+2)=='#'){
res=res+(char)('a'+(s.charAt(index)-48)*10+s.charAt(index+1)-49);
index+=2;
    }else{res=res+(char)('a'+s.charAt(index)-49);

    }
    }else{res=res+(char)('a'+s.charAt(index)-49);}
    
}

return res;
    }
}
```