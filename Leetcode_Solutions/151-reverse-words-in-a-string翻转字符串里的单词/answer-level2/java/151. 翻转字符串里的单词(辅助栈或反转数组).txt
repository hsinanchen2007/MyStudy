### 解题思路
主要思路：1.去除头尾空格2.利用辅助栈先进后出来翻转，同时可以根据栈中元素是否空格来排除字符串中间一个以上的空格
2.递归：
2.1递归终止条件：指针走到字符串最后
2.2递归：如果取出的字符不是空格就加到tmp字符串中，index++
2.3如果是空格，就将tmp加入栈，index++，同时tmp重置
3.结束循环的时候还得将最后一个tmp入栈！！！
4.出栈完成
### 代码

```java
class Solution {
    String res=new String("");
    Stack<String> stack=new Stack<>();
    public String reverseWords(String s) {
        s.trim();
        char[] str=s.toCharArray();
        String tmp=new String("");
        int index=0;
        while(index<str.length){//将字符串里的子字符串循环入栈
            char c=str[index];
            if(c==' '){
                stack.push(tmp);
                tmp="";
                index++;
            }else{
                tmp=tmp+c;
                index++;
            }
        }
        stack.push(tmp);
        while(!stack.isEmpty()){//栈里字符串出栈输出结果
            String s1=stack.pop();
            if(s1!=""){
                res=res+s1+" ";
            }
        }
        return res.trim();
    }
}
```
## 简易写法
```
class Solution {
    String res=new String("");
    public String reverseWords(String s) {
        String[] str=s.trim().split(" ") ;
        for(int i=str.length-1;i>=0;i--){
            if(str[i].equals(""))continue;
            res=res+str[i]+" ";
        }
        return res.trim();
    }
}
```
