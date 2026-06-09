```
 public static String toLowerCase(String str) { //第一种解决方案
        String s= str.toLowerCase();
        return s;
    }
    public static String toLowerCase2(String str){//第二种解决方案 通过ascii来解决 ascii对应65为A 90为Z 97为a 122为z
        char[] s=new char[str.length()];
        char c;
        for(int i=0;i<str.length();i++){
            c=str.charAt(i);
            if(c>=65&&c<=90){
                c=(char)(c+32);
            }
            s[i]=c;
        }
        return new String(s);
    }
```
