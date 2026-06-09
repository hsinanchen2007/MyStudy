### 解题思路
用一个栈，碰到')'就一直pop，得到false和true，直到碰到'('。碰到'('后，空pop一下，取出前面的运算符!或者&或者|。把运算结果在压入栈。

### 代码

```java
class Solution {
    public boolean parseBoolExpr(String expression) {
        boolean ret = true ;
        Stack<Character> sta = new Stack<>() ;
        for(char ch:expression.toCharArray())        {
            int trueCount = 0 ;
            int falseCount = 0 ;
            if(ch==','){
                continue ;
            }
            else if(ch!=')'){
                sta.push(ch);
            }
            else{
                while(sta.peek()!='('){
                    char chTemp0 ;
                    chTemp0 = sta.pop();
                    if(chTemp0=='t'){
                        trueCount++;
                    }
                    else if(chTemp0=='f'){
                        falseCount++;
                    }
                }
                char chTemp1=sta.pop();
                chTemp1=sta.pop();
                if(chTemp1=='&'){
                    if(trueCount > 0 && falseCount ==0)
                    sta.push('t');
                    else
                    sta.push('f');
                }
                if(chTemp1=='|'){
                    if(trueCount > 0 )
                    sta.push('t');
                    else
                    sta.push('f');
                }
                if(chTemp1=='!'){
                    if(trueCount > 0 )
                    sta.push('f');
                    else
                    sta.push('t');
                }
            }
        }
        if(sta.peek()=='f'){
            return false;
        }
        else{
            return true ;
        }

    }
}
```