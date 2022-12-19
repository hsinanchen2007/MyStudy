### 解题思路


### 代码

```java
class Solution {
    public boolean isNumber(String s) {
        if(s==null||s.length()==0) return false;
        boolean hasE = false;//是否出现了e
        boolean isnum = false;//判断当前部分是不是数
        boolean hasP = false;
        char[] c = s.trim().toCharArray();
        int begin=0;
        for(int i=0;i<c.length;i++){
            if(c[i]=='+'||c[i]=='-'){
                if(i!=begin&&!equalE(c[i-1])){
                    return false;
                }
                isnum = false;
                continue;
            }
            if(equalE(c[i])){
                if(!isnum)  return false;
                if(hasE) return false;
                hasE=true;
                if(isnum){
                    isnum = false;
                }else{
                    return false;
                }
                continue;
            }
            if(c[i]=='.'){
                if(hasP||hasE)  return false;
                hasP = true;                
                continue;
            }
            if(!Character.isDigit(c[i])){
                return false;
            }else{
                isnum = true;
            }
        }
        return isnum;
    }

    public boolean equalE(char ch){
        return ch=='e'||ch=='E';
    }
}
```