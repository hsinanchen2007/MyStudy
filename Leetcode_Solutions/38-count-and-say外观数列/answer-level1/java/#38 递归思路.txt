### 解题思路
用了递归来解决这个问题，代码写的可能不够优雅，但是解决了问题了
有大牛有更优雅的给我参考一下嘛？

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        return countSay(n);
    }

    public String countSay(int n){
        if(n == 1){
            return "1";
        }

        String str = countSay(n - 1);

        Stack stack = new Stack();
        int count = 0;
        StringBuffer result = new StringBuffer();

        for(char strChar : str.toCharArray()){
            if(stack.isEmpty()){
                stack.push(strChar);
                count++;
                continue;
            }//if

            if((char)stack.peek() == strChar){
                count++;
            }else{
                result.append(String.valueOf(count)).append(String.valueOf(stack.peek()));
                count = 1;
                stack.push(strChar);
            }//if
        }//for

        if(count != 0){
            result.append(String.valueOf(count)).append(String.valueOf(stack.peek()));
        }
        return result.toString();
    }
}
```