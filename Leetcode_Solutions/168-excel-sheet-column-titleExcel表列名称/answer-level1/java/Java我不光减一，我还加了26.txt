```
public static String convertToTitle(int n) {
        StringBuffer sb = new StringBuffer();
        while(n>26){
            int remind=0;
            remind = n%26;
            if(remind==0){
                n -= 1;
                remind += 26;
            }
            n=n/26;
            sb.append((char)(remind+64));
        }
        sb.append((char)(n+64));
        return sb.reverse().toString();
    }
```
好刺激 100% 80%