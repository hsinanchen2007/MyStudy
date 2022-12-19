**思路：**
    既然要想单词能拼出来，那么单词的字母肯定在字母表中。所以扫描每个单词的字符，如果在字母表中，则在字母表中删掉这个字母（为了防止重复）。如果不在直接下一个单词。
**Code：**
```
    public static int countCharacters(String[] words, String chars) {
        StringBuilder sb ;
        String temp;
        int length=0;
        int count;
        for(int i=0;i<words.length;i++){
            sb = new StringBuilder(chars);
            temp = words[i];
            count=0;
            for(int j=0;j<temp.length();j++){
                //扫描每个字符，看是否在sb里面
                String t = ""+sb;
                int index = t.indexOf(temp.charAt(j));
                if(index!=-1){
                    //如果在，那么删去这个元素
                    count++;
                    sb.deleteCharAt(index);
                }else{
                    count=0;
                    break;
                }
            }//of for
            length+=count;
        }
        return length;
    }
    //判断位置 在的话返回下标 不在返回-1
    public static int ifIn(char a,StringBuilder s){
        String t = ""+s;
        return t.indexOf(a);
    }
}
```
