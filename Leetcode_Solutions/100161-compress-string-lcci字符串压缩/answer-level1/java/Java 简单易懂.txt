```
class Solution {
    public String compressString(String S) {
        //条件校验
        if(S.length() <=2){
            return S;
        }
        StringBuilder builder = new StringBuilder();
        char[] chars = S.toCharArray();
        int count =1;
        for(int i =1 ; i < chars.length; i++){
            String str = String.valueOf(chars[i]);
            if(chars[i] == chars[i-1]){  
                count++;
            }else{
                builder.append(chars[i-1]);
                builder.append(count);
                count=1;
            }
        }        
        //对最后的进行处理
        builder.append(chars[chars.length -1]).append(count);
        if(builder.toString().length() > S.length()){
            return S;
        }else{
            return builder.toString();
        }
    }
}
```
