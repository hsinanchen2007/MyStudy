```
public String replaceSpace(String s) {
        StringBuffer sb=new StringBuffer();
        for(char c:s.toCharArray()){
            if(c==' ')
                sb.append("%20");
            else
                sb.append(c);
        }
        return sb.toString();
    }
```
