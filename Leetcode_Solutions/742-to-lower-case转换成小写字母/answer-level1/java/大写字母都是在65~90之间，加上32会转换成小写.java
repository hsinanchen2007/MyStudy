大写字母都是在65~90之间，加上32会转换成小写
```
public String toLowerCase(String str) {
        //创建一个字符数组，用于存储传换后的小写字母
        char [] c = new char[str.length()];
        char z = 0; //定义一个字符变量
        //遍历字符串
        for (int i=0;i<str.length();i++){
            //把字符串转换成字符
             z = str.charAt(i);  //返回指定索引下的字符
            if(z>=65&&z<=90){ //说明是大写字母
                z+=32; //转换成小写字母
            }
            c[i] = z;  //加入到字符数组
        }
        //把字符数组转换成字符串返回
        return new String(c);
    }
```
