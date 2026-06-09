### 解题思路
题目的坑比较多，说一个坑最大的地方：像"path\n    file.txt"这种，直接把空格当做文件名的一部分即可
要注意题目问的是"文件"的最长绝对路径，"文件"指的是带有.的文件名

### 代码

```java
class Solution {
    public int lengthLongestPath(String input) {
        input = input+"\n";//进行统一处理,末尾加个\n不影响结果，不用判断特殊情况
        int max = 0;
        Stack<String> stack = new Stack<String>();//进行字符串拼接 文件（夹）名_当前的目录层级
        StringBuilder sb = new StringBuilder();
        int curLen = 0;//记录当前目录长度
        int count = 0;//记录\t的个数,即目录层级
        int pre = count;//记录上一个count
        for(int i=0;i<input.length();){
            char ch = input.charAt(i);
            // System.out.print(ch+"");
            if(ch=='\n'){
                i++;
                //计算下一个文件(夹)的目录层级
                while(i<input.length() && input.charAt(i)=='\t'){
                    count++;
                    i++;
                }
                int len = sb.length();
                // System.out.println("   "+pre+"   length:"+len);
                if(stack.isEmpty()){//栈为空，直接压入
                    stack.push(sb.toString()+"_"+pre);       
                    curLen = len;                                    
                }else{
                    String[] temp = stack.peek().split("_");
                    if(pre>Integer.valueOf(temp[1])){//是子目录
                        /*根据测试用例，发现要把\n\t替换为/，
                        *例如假设给你“path\n\tfile.txt”，返回的结果应该是13，
                        * 最长绝对路径是"path/file.txt",注意中间需要添加额外的斜杠
                        */ 
                        curLen = curLen+len+1;
                        stack.push(sb.toString()+"_"+pre);
                    }else{//是并行目录
                        while(!stack.isEmpty() && pre<=Integer.valueOf(temp[1])){
                            stack.pop();
                            /*
                            *不仅要减去上一个字符串的长度还要减去添加的/,
                            *若一直pop到栈空，则curLen=-1,与下面的curLen+len+1中的1相抵消
                            */
                            curLen = curLen-temp[0].length()-1;
                            if(!stack.isEmpty()){
                                temp = stack.peek().split("_");
                            }
                        }
                        curLen = curLen+len+1;
                        stack.push(sb.toString()+"_"+pre);
                    }
                }
                pre = count;
                count = 0;
                if(sb.indexOf(".")!=-1){//判断是否是文件
                    max = Math.max(max,curLen);
                }
                sb.delete(0,sb.length());
            }else{
                sb.append(ch);
                i++;
            }
        }
        return max;
    }

}
```