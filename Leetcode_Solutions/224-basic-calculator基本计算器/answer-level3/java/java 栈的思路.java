### 解题思路
使用两个栈，一个栈保存数字，一个栈保存其他的字符

（1）遇到数字就进第一个栈，这时候可能会出现>9的数字，使用last_number和scale两个变量将这个数字计算出来
如:123，计算顺序就是1，1\*10+2，12\*10+3
（2）遇到右括号的时候，将左侧的全部出栈计算，直到遇见第一个左括号
如: (1-2+3) 当遇到最后一个右括号，计算1-2+3的值，然后存入第一个数字栈中
*这里有一个问题，比如说1-2+3进栈了，但是出来的却是3+2-1，肯定不对了，所以我这里用了pop_to_left将栈的顺序翻转一下。
（3）遇到结束的时候，(1+2+3)那么程序就结束了，返回数字栈的第一个内容即可，但是1+2+3,程序还不知道退出，这时候再计算一下，见函数last_cal

另外last_cal和pop_to_left逻辑差不多，就是颠倒一下原来的栈，防止负数计算错误，这里没有将这两个类合二为一，方便大家理解。

### 代码

```java
class Solution {

    public void pop_to_left(Stack<Integer> stack1,Stack<Character> stack2) {

        Stack<Integer> tmp_stack1 = new Stack<Integer>();
        Stack<Character> tmp_stack2 = new Stack<Character>();

        while(stack2.peek()!='(') {
            tmp_stack1.push(stack1.pop());
            
            tmp_stack2.push(stack2.pop());
        }
        tmp_stack1.push(stack1.pop());
        stack2.pop();

        while(!tmp_stack2.empty()) {
            if(tmp_stack2.peek() == '+') {
                tmp_stack1.push(tmp_stack1.pop()+tmp_stack1.pop());
            }else{
                tmp_stack1.push(tmp_stack1.pop()-tmp_stack1.pop());
            }
            tmp_stack2.pop();
        }

        stack1.push(tmp_stack1.pop());
        
    }

    public void last_cal(Stack<Integer> stack1,Stack<Character> stack2) {

        Stack<Integer> tmp_stack1 = new Stack<Integer>();
        Stack<Character> tmp_stack2 = new Stack<Character>();

        while(!stack2.empty()) {
            tmp_stack1.push(stack1.pop());
            
            tmp_stack2.push(stack2.pop());
        }
        tmp_stack1.push(stack1.pop());

        while(!tmp_stack2.empty()) {
            if(tmp_stack2.peek() == '+') {
                tmp_stack1.push(tmp_stack1.pop()+tmp_stack1.pop());
            }else{
                tmp_stack1.push(tmp_stack1.pop()-tmp_stack1.pop());
            }
            tmp_stack2.pop();
        }

        stack1.push(tmp_stack1.pop());
        
    }

    public int calculate(String s) {

        Stack<Integer> stack1 = new Stack<>();
        Stack<Character> stack2 = new Stack<>();

        boolean last_number = false;
        int scale = 10;

        for(int i =0;i<=s.length()-1;++i) {
            char current = s.charAt(i);
            if(current == ' ') continue;

            if(current == ')') {
                //退栈
                pop_to_left(stack1,stack2);
                last_number = false;
                scale = 10;
         

            }else {
                //进入
                if(!Character.isDigit(current)) {
                    stack2.push(current);
                    last_number = false;
                    scale = 10;
                  
                }else{
                    int current_num = (int)(current -'0');
                    if(last_number) {
                        stack1.push(stack1.pop()*scale+current_num);
                            // System.out.println(stack1);
                        scale = scale;

                    }else{
                        stack1.push(current_num);
                    }
                    if(i+1<=s.length()-1) {

                    }
                    last_number = true;
                    
                }

            }
        }
        System.out.println(stack1);
        System.out.println(stack2);

        last_cal(stack1,stack2);
  
        return stack1.pop();
    }
}
```