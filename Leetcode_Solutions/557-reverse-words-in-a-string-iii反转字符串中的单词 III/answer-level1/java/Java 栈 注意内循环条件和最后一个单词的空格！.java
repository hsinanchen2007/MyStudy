要点：内循环条件；最后一个单词不用再加空格！
用栈的结构正好可以实现反转，注意在判断一个单词结束之后，要在外面i++,避免全都判断为空格！
```
class Solution {
    public String reverseWords(String s) {

        //char[] charArray = s.toCharArray();
        int length = s.length();
        StringBuffer conv = new StringBuffer();
        StringBuffer sb = new StringBuffer();
        Stack stack = new Stack();
        int i = 0;
        int k = 0;
        
        while(i<length)
        {
            while(s.charAt(i) != ' ')
            {
                stack.push(s.charAt(i));
                if(i ==length-1)
                {
                    break;
                }else{i++;}
                
            }
        
            while(stack.empty() == false)
            {
                conv.append(stack.pop());
            }
            if(i < length-1){conv.append(" ");}
            sb.append(conv);
            conv = new StringBuffer();
            //k++;
            i++;
      }
        String result = sb.toString();  
        return result;
}
}
```
