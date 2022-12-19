解题思路：1当要插入的不是c时入栈；
2当插入c时只有b、a依次出栈,才能说明abc连续的；否则就不是有效的。
3.当字符串s全部插入完后，判断栈是否为空，唯恐就是有效的。
```
public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        int length =s.length();
        for(int i = 0;i<length;i++){
            if(s.charAt(i)!='c'){
                //不等于c时，全部入栈
                stack.push(s.charAt(i));
            }else {
                if(!stack.empty()&&stack.pop()=='b'){
                    if(!stack.empty()&&stack.pop()=='a'){
                        //等于c，只有依次从栈顶弹出b,a才能通过；否则abc不连续，返回false
                    }else {
                        return false;
                    }
                }else {
                    return false;
                }

            }
        }
        return stack.empty();

    }
```
