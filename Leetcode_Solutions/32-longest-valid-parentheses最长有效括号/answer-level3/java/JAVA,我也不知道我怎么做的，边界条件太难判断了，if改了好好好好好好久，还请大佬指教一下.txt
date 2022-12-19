

```
public int longestValidParentheses(String s) {
    if(s.length()==0 || s.length()==1)
        return 0;
    byte[] str = s.getBytes();
    int[] count = new int[s.length()];
    if (str[0]=='(')
        count[0] = 1;
    else
        count[0] = 0;
    int length = s.length();
    for (int i = 1 ; i <length ; i++) {
        if (str[i]=='(')
            count[i] = count[i-1] + 1;
        else
            count[i] = count[i-1]-1 > 0 ? count[i-1]-1 : 0;
    }
    int len = 0;

    to :for (int i = length-1 ,temp=count[0]; i >0 ; i--) {
        if( count[i]<count[i-1] ){
            for (int j = i-1; j >-1 ; j--) {
                if(count[j] == count[i]){
                    len = len > i-j ? len : i-j;
                    if( j>0 && count[j-1] <= count[j]){
                        i = j;
                        continue  to;
                    }
                }
            }
            if(count[0]>count[i]){
                len = len > i+1 ? len : i+1;
                i=0;
            }
        }
    }
    return len;
}
```
