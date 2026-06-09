### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String decodeString(String s) {
        StringBuilder result = new StringBuilder();
        int num = 0;
        LinkedList<Integer> stackNum = new LinkedList<>();
        LinkedList<String> stackRes = new LinkedList<>();
        for (Character ch : s.toCharArray()) {
            if (ch == '[') {
                stackNum.addLast(num);
                stackRes.addLast(result.toString());
                num = 0;
                result = new StringBuilder();
            }
            else if(ch == ']') {
                StringBuilder tmp = new StringBuilder();
                int curNum = stackNum.removeLast();
                for(int i = 0; i < curNum; i++) {
                    tmp.append(result);
                } 
                result = new StringBuilder(stackRes.removeLast() + tmp);
            } else if(ch >= '0' && ch <= '9'){
                //精妙的多数字计算法
                num = num * 10 + Character.getNumericValue(ch);
            } else {
                result.append(ch);
            } 
        }
        return result.toString(); 
    }
}
```