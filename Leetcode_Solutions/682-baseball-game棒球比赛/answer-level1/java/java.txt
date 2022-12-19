### 解题思路
代码如下
### 代码

```java
class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> resultStack = new Stack();
        int length = ops.length;
        for(String item:ops){
            if("C".equals(item)){
                resultStack.pop();
                length = length-2;
            }else if("D".equals(item)){
                resultStack.push(resultStack.peek()*2);
            }else if("+".equals(item)){
                Integer first = resultStack.pop();
                Integer second = resultStack.pop();
                resultStack.push(second);
                resultStack.push(first);
                resultStack.push(first+second);
            }else{
                resultStack.push(Integer.valueOf(item));
            }
        }
        int result = 0;
        for(int i = 0;i < length;i++){
            result=result+resultStack.pop();
        }
        return result;
    }
}
```