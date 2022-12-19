### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        // 如何构造：1、求可构造最长长度。2、构造。
            int max = a+b+c;
            if( a > (b+c+1)*2 ) max = (b+c+1)*2+(b+c);
            if( b > (a+c+1)*2 ) max = (a+c+1)*2+(a+c);
            if( c > (b+a+1)*2 ) max = (b+a+1)*2+(b+a);

            // 每一次取最多的放在这一位，若前两位已经是该值，更换为次多的字符。
            StringBuilder sb = new StringBuilder();
            for( int i=0; i<max; i++ ){
                if( a >=b && a>=c){
                    if( i>=2 && sb.charAt(i-1)=='a' && sb.charAt(i-2)=='a' ){
                        //替换为次多字符
                        if( b >= c ){
                            sb.append("b");b--;
                        }else{
                            sb.append("c");c--;
                        }
                    }else{
                        sb.append("a");
                        a--;
                    }

                }else if( b >=a && b>=c){
                    if( i>=2 && sb.charAt(i-1)=='b' && sb.charAt(i-2)=='b' ){
                        //替换为次多字符
                        if( a >= c ){
                            sb.append("a");a--;
                        }else{
                            sb.append("c");c--;
                        }
                    }else{
                        sb.append("b");
                        b--;
                    }

                }else if( c >=a && c>=b){
                    if( i>=2 && sb.charAt(i-1)=='c' && sb.charAt(i-2)=='c' ){
                        //替换为次多字符
                        if( a >= b ){
                            sb.append("a");a--;
                        }else{
                            sb.append("b");b--;
                        }
                    }else{
                        sb.append("c");
                        c--;
                    }
                }
            }
            return sb.toString();
    }
}
```