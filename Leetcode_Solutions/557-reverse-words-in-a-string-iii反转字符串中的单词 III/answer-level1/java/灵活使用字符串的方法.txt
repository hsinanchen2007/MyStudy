class Solution {
    public String reverseWords(String s) {
        StringBuilder str=new StringBuilder();
        char[] c=s.toCharArray();
        String[] st=new String[s.length()];
        int count=0; //定义一个变量，记录数组st的长度
        if(s.equals("")){  //如果s字符串只有一个空格，直接返回该字符串
            return s;
        }
        for(int i=0;i<c.length;i++){
            if(c[i]==' '){  //如果遇到空格，就将str的字符颠倒后存到数组st中
                st[count++]=str.reverse().toString()+" ";
                str.setLength(0);
            }else{          //否则不停的向str中追加
                str.append(c[i]); 
            }
        }
        st[count]=str.reverse().toString(); //上一次循环执行完以后，还有最后一个字符串没用反转，将该字符串反转后存到数组中
        str.setLength(0);//重新清楚str的内容
        for(int i=0;i<=count;i++){
            str.append(st[i]);  //遍历数组st，将st中的元素放到str中
        }
        return str.toString(); //直接返回str
    }
}