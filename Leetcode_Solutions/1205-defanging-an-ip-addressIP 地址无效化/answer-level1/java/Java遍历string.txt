把stringstring直接转化为char数组，新建stringBuilder用来储存更改过的IP，通过遍历数组判断当前是否是“.”，据此来决定append到stringBuilder上面的是什么。
明明是遍历结果效率还挺高```
       char[] chars=address.toCharArray();
        StringBuilder stringBuilder=new StringBuilder();
        for (char c:chars) {
            if (c==".".charAt(0)){
                stringBuilder.append("[.]");
            }else {
                stringBuilder.append(c);
            }
        }
        return stringBuilder+"";
代码块
```
