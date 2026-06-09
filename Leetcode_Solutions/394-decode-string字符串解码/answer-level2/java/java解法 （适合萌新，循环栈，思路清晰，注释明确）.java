本题比较复杂的就是要考虑括号中套括号的情况，其实遇到这种情况第一反应就是要使用栈来进行解答。使用两个栈，一个用来存储数字，另一个用来存储当前的字符串（当遇到‘[‘时存入，当遇到]时要弹出与【】内的字符串组成新的字符串）。下面的代码写了遇到四种情况。
**接下来来个例子："3[a]2[b4[F]c]"**
1：数字3。3入栈此时，num=3，numStack = “”， StringStack = “”；
2：左括号。将num入栈，将sb入栈，num=0，numStack = 3， StringStack = “”
3.： a。将字母添加进sb，其他不变，sb为a
4.右括号。将【】中的与之前的字符串（字符串栈中）组合起来，newString = aaa,oldString = "";
sb=aaa,
**一个坑**：这里我想大家就会有个疑问了，为什么在遇到左括号时清空num，而不是在右括号之后清空num呢。
**考虑这个例子**："2[ab3[cd]]4[xy]"，如果不在遇到左括号时就将数字清空，当我们到第二个左括号时，num已经变成了23，所以需要遇到左括号就清空一下num，也符合我们的题意，num后面就会紧跟着【】，所以这个num只和【】中的字母有关系。下次在遇到【】时，必须要让【】只匹配他前面，再往前的不匹配。所以要遇到【，就要将num清空。
**第二个坑**：为什么我们不在遇到右括号处理之后就把结果压入栈中呢，理由如下：因为我们只有遇到左括号才能说明，当前的sb是与后面的左括号以后的字符串是并列关系，只有这时才会分oldString与newString。
话不多说我们继续往下走
5.数字2，num = 2，numStack = “”，StringStack =“”, 
6.左括号，numStack=2，sb入栈，StringStack=aaa，num=0，sb=“”
7.b，sb=b，其他不变
8.4，num=4，其他不变
9.左括号，numStack={2，4}，StringStack={aaa，b}，sb=“”，num=0
10.F，sb=F，其他不变
11.右括号，numStack出栈，与F组合newString为FFFF（二次元莫名喜感），弹出StringStack的栈顶（b）为oldString，组合之后sb为bFFFF。
12.c，sb=bFFFFc
13.右括号，numStack出栈（2），组合厚度newString就是bFFFFcbFFFFc，oldString为aaa。组合之后为aaabFFFFcbFFFFc。
返回aaabFFFFc。好累，但是这个例子比较好，你说不好？？？我不要你觉得，我要我觉得。
```java
class Solution {
    //使用两个栈（存储数字和字符串，每次遇到]，应该先使用最新的数字，所以使用先进后出的栈）
    //有四种情况：
    //1.数字：有可能是连续的数字，比如44
    //用num存储
    //2.左括号[
    //1）.遇到该字符要将数字入栈，以便用于遇到]时将[]中的字符串进行处理
    //2）.要将之前累积的sb入栈，用于在之后遇到]时，将新做出来的字符串与之前的字符串拼接起来
    //3）.要将sb和num清空，要去记录左左括号后面的东西惹    
    //3.右括号]
    //先将数字（最新的）出栈，组成数字*res，之后再将字符串出栈，将旧字符串与新组成的字符串组合到一起，组成sb。
    //4.字母
    //将字母加入sb
    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        Stack<Integer>numStack = new Stack<>();
        Stack<String>StringStack = new Stack<>();
        int num = 0;
        for(int i=0;i<s.length();i++)
        {
            char now = s.charAt(i);
            if(Character.isDigit(now))
            {
                //可能是连续的呀
                num = num*10+ now-'0';
            }
            //到了这里要把前面做好的StringBuilder入栈
            else if(now == '[')
            {
                //这里的sb就是从上一个[到这个[的
                //比如3【a2【c】】中的a，也是3[a]2[bc]的aaa。
                numStack.push(num);
                StringStack.push(sb.toString());
                //清空sb
                sb.delete(0,sb.length());
                num = 0;
            }
           else if(now == ']')
            {

                String old = StringStack.pop();
                String curr = sb.toString();
                //本身就有一次了，咱们就让他再往里加num-1次就好
                int times = numStack.pop()-1;
                for(int j=0;j<times;j++)
                {
                    sb.append(curr);
                }
                //将old与新的添加进去。old直接放在所有的最前面即可。
                sb.insert(0,old);
            }
            //可能是大写
            else
            {
                sb.append(now);
            }
        }
        return sb.toString();  
    }
}
```
