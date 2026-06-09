### 解题思路
1、构造堆栈stack,从左至右遍历字符串s
2、判断当前字符是否是],如果不是压入到stack
3、如果当前字符是],那么就构造一个字符串变量str,用于保存[]之间的字符串
4、对于当前堆栈逆向寻找第一个出现的[,在遍历的过程中将栈中的元素字符charStr拼接到str
     str = charStr+str;
     同时将charStr弹出
5、找到[后，先弹出一次，目的是将'['字符弹出
6、然后寻找[前面的数字,注意这里有个陷阱,数字有可能是二位数，三位数等等
    int num = 0;//num的值
    int numIndex = 0;//10的幂次方
    while(!stack.isEmpty() && stack.peek()-'0'>=0 && '9'-stack.peek()>=0){
        num += (stack.pop()-'0')*(int)Math.pow(10,numIndex++);
    }
7、然后将num*str这样的字符串压入到栈中
    可以利用二重循环,如下所示:
    for(int i = 1;i<=num;i++){
        for(int j=0;j<str.length;j++){
           stack.push(str.charAt(j));
        }
    }
8、当字符串s遍历完成后，将stack从栈底到栈顶输出

空间复杂度O(s.length) 因为只用到了栈，及若干个临时字符串变量
时间复杂度O(s.length) 只遍历了一次字符串,途中对于堆栈的遍历属于跟字符串的复杂程度有关系
要注意的点就是对栈的操作要注意非空判断和取出[前面的正确数字    

### 代码

```java
class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<Character>();
        for(int i = 0;i<s.length();i++){
            char currentChar = s.charAt(i);
            if(currentChar!=']'){
                stack.push(currentChar);
            }else{
                //寻找stack里面最近的一个[
                String charStr = "";
                 while(stack.peek()!='['){
                    //因为一定可以找到左边的括号,所以不用判断数组越界
                    Character charItem = stack.pop();
                    charStr=charItem+charStr;
                }
                //找到了[,这个时候要找到[前面的数字
                stack.pop();//第一次弹出[
                //寻找数字
                int numIndex = 0;
                int num = 0;
                while(!stack.isEmpty() && stack.peek()-'0'>=0 && '9'-stack.peek()>=0){
                    num+= (stack.pop()-'0')*(int)Math.pow(10,numIndex++);
                }
                //这样新的字符串就是num*charStr
                for(int j= 1;j<=num;j++){
                    for(int k=0;k<charStr.length();k++){
                        stack.push(charStr.charAt(k));
                    }
                }
            }
        }
        String result = "";
        for(int i = 0;i<stack.size();i++){
            result = result +stack.get(i);
        }
        return result;
    }
}
```