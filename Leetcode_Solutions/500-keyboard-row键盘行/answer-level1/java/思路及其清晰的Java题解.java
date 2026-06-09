```
 public String[] findWords(String[] words) {
        String str1="qwertyuiop";
        String str2="asdfghjkl";
        String str3="zxcvbnm";
        String[] res=new String[words.length];
        byte count=0;
        for(int i=0;i<words.length;i++){
            int j=0;
            int len=words[i].length();
            String str = words[i].toLowerCase();
            //判断是否在第一行中
            while(j<len&&(str1.indexOf(str.charAt(j))!=-1)){
                j++;
            }
            //满足if条件说明当前字符串有字符存在第一行字符
            //但是不全是第一行的，不满足条件，直接遍历下一个字符串
            if(j>0&&j<len){
                continue;
            }
            //同样的，判断是否在第二行中
            while(j<len&&(str2.indexOf(str.charAt(j))!=-1)){
                j++;
            }
            if(j>0&&j<len){
                continue;
            }
            //判断是否在第三行中
            while(j<len&&(str3.indexOf(str.charAt(j))!=-1)){
                j++;
            }
            //满足此if条件说明当前字符串在某一行中
            if(j==len){
                res[count++]=words[i];
            }
        }
        //将res数组中有效数据拷贝到temp数组中返回
        String[] temp=new String[count];
        for(int i=0;i<count;i++){
            temp[i]=res[i];
        }
        return temp;
    }
```
