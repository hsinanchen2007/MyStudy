根据前边的经验，用数字栈比较容易理解
截取字符串时候开始位置，也就是栈底元素位置。
```
public String removeOuterParentheses(String S) {
        //利用数字栈的方式
        StringBuffer sb = new StringBuffer();
        int index= 0; //标记位，用于记录栈底字符下标。
        int stack=0;
        for (int i=0;i<S.length();i++){
            char c = S.charAt(i); //返回指定索引位的字符
            if(c=='('){
                stack++;
            }
            if(c==')'){
                stack--;
            }
            if(stack == 1 &&'('==S.charAt(i)){
                index = i;  //记录一下首位
            }
            if(stack ==0){ //说明匹配到一串字符
                //截取字符串追加到sb里边
                String s = S.substring(index + 1, i);
                sb.append(s);
            }
        }
        return sb.toString();
    }
```
