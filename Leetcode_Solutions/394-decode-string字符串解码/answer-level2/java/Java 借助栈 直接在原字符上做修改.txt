**解法一**

借助栈直接在原字符上做改动

```java
public String decodeString(String s) {
    if (s==null || s.length()<=0) {
        return "";
    }
    //转换为StringBuilder比较好处理,且效率较高
    StringBuilder sb=new StringBuilder(s);
    Stack<Integer>  stack=new Stack<>();
    int i=0;//遍历索引
    while(i<sb.length()) {
        if (sb.charAt(i)=='[') {
            stack.push(i);
        }else if(sb.charAt(i)==']'){
            int left=stack.pop();//对应左括号索引
            String temp=sb.substring(left+1,i);//相邻括号中的字符
            int preInt=left;
            //'['前的数字,一开始以为只是个位数,还是挺麻烦的
            while(preInt-1>=0 && sb.charAt(preInt-1)>='0' && sb.charAt(preInt-1) <='9'){
                preInt--;
            }
            //repeat次数
            int repeat=Integer.valueOf(sb.substring(preInt,left));
            //删除 k[encoded_string] 
            sb.delete(preInt,Math.min(i+1,sb.length()));
            for (int j=0;j<repeat;j++) {
                //从k位置重新插入字符
                sb.insert(preInt,temp);
            }
            //重新定位索引到尾部
            i=preInt+(repeat*temp.length())-1;
        }
        i++;
    }
    return sb.toString();
}
```
一开始是想用一个额外的String来保存结果，结果发现比较麻烦，索性直接将原字符转换为StringBuilder，然后借助api直接在原字符上做改动，因为是在原字符上做改动，所以索引的变化需要额外的注意，这也是最麻烦的一点，需要停下来稍微思考下才能确定，其他的还好，正常的思路，最初WA了一发是因为忽略了前面的数字可能是多位数😂

**解法二**

递归的方式，改成`StringBuilder`应该会好一点😂

```java
private int index=0; //字符索引下标

public String decodeString(String s) {
    if (s==null || s.length()<=0) {
        return "";
    }
    String sb="";
    while(index<s.length()){
        if (s.charAt(index)==']') { //遇到右括号就结束
            index++;//index定位到右括号下一个
            return sb;
        }else if(s.charAt(index)>='0' && s.charAt(index)<='9'){
            int temp=index;
            while(index<s.length() && s.charAt(index)!='['){
                index++;
            }
            int repeat=Integer.valueOf(s.substring(temp,index));
            index++;//跳过'['
            String rs=decodeString(s);//从左括号开始
            for (int i=0;i<repeat;i++) {
                sb+=rs;
            }
        }else{
            sb+=s.charAt(index++);
        }
    }
    return sb;
}
```