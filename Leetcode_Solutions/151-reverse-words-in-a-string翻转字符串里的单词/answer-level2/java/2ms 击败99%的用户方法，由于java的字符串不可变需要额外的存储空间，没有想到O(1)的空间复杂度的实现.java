①先去掉首位空格，
②倒叙遍历字符串数组
③如果数组元素包含空格则去掉所有空格，只添加不包含空格的字符串元素；
④除了最后一位每添加一个不包含空格的字符串元素，手动添加一个空格
```
        String emptyStr=" ";
        final String[] s1 = s.trim().split(emptyStr);
        StringBuilder sb=new StringBuilder();
        for (int i = s1.length - 1; i >= 0; i--) {
            String str=s1[i];
           while (str.contains(emptyStr)){
               str=str.replaceAll(emptyStr,"");
           }
            if ("".equals(str)){
                continue;
            }
            sb.append(str);
            if (i!=0){
                sb.append(emptyStr);
            }
        }
        return sb.toString();
```
