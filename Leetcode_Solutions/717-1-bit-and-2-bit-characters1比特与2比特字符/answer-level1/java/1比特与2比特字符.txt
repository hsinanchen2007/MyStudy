先上代码：
```java
public boolean isOneBitCharacter(int[] bits) {
        if(bits.length>1000||bits.length==0) return false;
        Stack<Integer> stack = new Stack<>();
        boolean sym = false;
        for(int i=0;i<bits.length;i++){
           if(bits[i]==1){//元素为1
               if(stack.isEmpty())
                  stack.push(bits[i]);//并且栈为空则入栈
               else if(!stack.isEmpty()&&(i+1)==bits.length)//如果扫描到最后一个元素，并且此时栈还是不为空，则可以证明最后一个字符不是一个一比特字符
                   sym = false;
               else
                  stack.pop();//如果栈不为空，把栈中数据pop
           }else{//元素为0
               if(!stack.isEmpty())
                   stack.pop();//如果栈不为空，把栈中数据pop
               else if(stack.isEmpty()&&(i+1)==bits.length){//如果扫描到最后一个元素，并且此时栈还是为空，则可以证明最后一个字符是一个一比特字符
                   sym = true;
               }
           }
           
        }
        return sym;
    }

```