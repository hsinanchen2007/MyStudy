把入参字符串转成char数组，遍历一遍发现到目标字符. 就转成字符串【.】，添加到创建的字符串里。最后输出该字符串即可。
```
public String defangIPaddr(String address) {
        char[] all = address.toCharArray();
        String s = "";
         for(char c : all){
             if(c == '.'){
                s += "[.]";
             } else{
                 s += String.valueOf(c);
             }
         }
        
         return s;
    }
```

