```
public String compressString(String S) {
        StringBuilder sb = new StringBuilder(String.valueOf(S.charAt(0)));
        int len = S.length();
        int count = 1;
        for (int i = 1; i < len; i++) {
            String lastStr = String.valueOf(S.charAt(i-1));
            String str = String.valueOf(S.charAt(i));
            if(lastStr.equals(str) && i != len-1){
                count++;
            } else if(lastStr.equals(str) && i == len-1) { //最后一步，确保拼接上字符
                count++;
                sb.append(count);
            } else {
                sb.append(count).append(str);
                count = 1;
            }
            //一旦长度超过S，就返回
            if(S.length() <= sb.toString().length()){
                return S;
            }
        }
        return sb.toString();
    }
```
