### 解题思路

双循环，如果位置处相同则将List中的位置置为m，如果secret对应位置没有对应的，则循环找List中的内容，如果List中有则置为mm。
同时要保证的是，第二个判断。

### 代码

```java
class Solution {
    public String getHint(String secret, String guess) {
        int a=0;
        int b=0;
        String[] c=new String[guess.length()];
        for(int i=0;i<guess.length();i++){
            c[i]=guess.substring(i,i+1);
        }
        for(int i=0;i<guess.length();i++){
            String f=secret.substring(i,i+1);
            if(f.equals(c[i])){
                a++;
                c[i]="m";
            }else{
                for(int t=0;t<guess.length();t++){
                    //同时要保证该位置不是与secret对应的
                    if(f.equals(c[t])&&!c[t].equals(secret.substring(t,t+1))){
                        b++;
                        c[t]="mm";
                       //要终止for循环，只找出第一个就好。
                        break;
                    }
                }
            }
        }
        StringBuilder res=new StringBuilder("");
        res.append(String.valueOf(a)).append("A").append(String.valueOf(b)).append("B");
        return res.toString();

    }
}
```