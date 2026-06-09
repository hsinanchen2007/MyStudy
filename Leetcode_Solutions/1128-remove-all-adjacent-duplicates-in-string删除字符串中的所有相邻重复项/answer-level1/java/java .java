### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> stack = new Stack<Character>();//定义一个存放字符的栈
        for(int i =0;i<S.length();i++){
            char c = S.charAt(i);//将字符串中的每个字符取出
           if(stack.isEmpty()){//判断，栈是不是空的，是空的说明直接压入
           stack.push(c);

           }else if(stack.peek()==c){//栈不为空，判断栈顶和你在字符串中打到的值是不是一样，一样将栈顶取出。c也不加入栈中
               stack.pop();
           }else{//如果 栈顶和你在字符串中取出的字符不想等。没什么好说的。压入栈就可以了
               stack.push(c);
           }
        }
        StringBuilder ret = new StringBuilder();
        int size =stack.size();//把 这个放在外面以免，我在循环里pop出stack元素后，导致stack大小变化
        for(int i =0;i<size;i++){
            ret.insert(0,stack.pop());//用insert不用append是因为我们从栈顶取出的顺序是倒着的。为了得到ca用插入，每次取出都让他插入第一个的位置。就得到我们要的顺序
        }
        return ret.toString();

    }
}
```