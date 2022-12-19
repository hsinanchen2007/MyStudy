```
 public static  String getHint(String secret, String guess) {
            int a =0;//公牛
            int b =0;//母牛
            //将两个字符串转化成StringBuilder，好调用setCharAt方法。

            StringBuilder se =new StringBuilder(secret);
            StringBuilder gu =new StringBuilder(guess);
            //遍历字符串
            for(int x=0;x<se.length();x++){
                if(se.charAt(x)==gu.charAt(x)){
                    a++;
                    gu.setCharAt(x,'A');
                    se.setCharAt(x,'B');
                    break;
                }
            }
            for (int x=0;x<se.length();x++){
                for (int y=0;y<gu.length();y++){
                    if(se.charAt(x)==gu.charAt(y)){
                        b++;
                        gu.setCharAt(y,'A');
                        break;
                    }
                }
            }
            StringBuilder s =new StringBuilder();
#            s.append(a).append('A').append(b).append('B');
            return s.toString();
//            System.out.println(s.toString());


        }
```
本人小白，学了二周JAVA了。用的非常基础的方法。。遍历字符串，然后将相同的改为别的字符的方式
