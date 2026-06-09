判断set的长度是否和字符串长度一样

```
       public boolean isUnique(String astr) {
            char[] chars = astr.toCharArray();
            HashSet set = new HashSet();
            for(int ch:chars){
                set.add(ch);
            }
            
            if(set.size() == astr.length()){
                return true;
            }
            return false;  
        } 
```         
