class Solution {
    public String toGoatLatin(String S) {
      if(S==null)return " ";
       StringBuilder a_letter=new StringBuilder();//存放末尾a字母个数
       StringBuilder sb=new StringBuilder();//结果字符串
      for(String str:S.split(" "))//通过空格分割字符串
      {
           a_letter.append("a");//下表索引每增加1，a个数就加1
           StringBuilder s=new StringBuilder();//对每个单词处理后存放
          
              if(String.valueOf(str.charAt(0)).matches("[aAeEuUiIOo]"))//正则表达式判断首字母是否为元音
              {
                  if(str.length()==1)s.append(str+"ma").append(a_letter);
                  else s.append(str.substring(0,str.length())+"ma").append(a_letter);
              }
             else
             {
                  if(str.length()==1)s.append(str+"ma").append(a_letter);
                  else s.append(str.substring(1,str.length())+String.valueOf(str.charAt(0))+"ma").append(a_letter);
             }
          
          sb.append(s+" ");
      }
       return sb.toString().trim(); 
    }
}