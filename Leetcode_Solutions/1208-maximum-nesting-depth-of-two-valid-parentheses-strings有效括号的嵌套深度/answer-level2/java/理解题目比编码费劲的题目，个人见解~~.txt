### 解题思路
这个题目废话太多，有点费解，硬着头皮理解了10分钟的题意，终于明白了啥意思。要使嵌套最小，将相邻的左括号（中间不包含右括号）拆到不同的子串中。lowB人士想到的如下两个方法，一个用栈的方式，性能比较差。另外一个是连续出现的左括号按照奇数偶数拆分开，遇到右括号把左括号对消就行，操作简单，性能比较好。

### 代码
方法一：
```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        Stack stack = new Stack();
        int[] answer = new int[seq.length()];
        for(int i = 0; i < seq.length(); i++){
            int num;
            String subStr = seq.substring(i, i+1);
            if(subStr.equals("(")){
                if(stack.isEmpty()){
                    num = 0;
                }else{
                    num = stack.peek().equals(0) ? 1 : 0;
                }
                stack.push(num);
                answer[i] = num;
            }else{
                num = stack.peek().equals(0) ? 0 : 1;
                stack.pop();
                answer[i] = num;
            }
        }
        return answer;
    }
}
```

方法二：
```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int left = 0;
        int[] answer = new int[seq.length()];
        for(int i = 0; i < seq.length(); i++){
            if(seq.charAt(i) == '('){
                answer[i] = left++ % 2;
            }else{
                answer[i] = (left-- - 1) % 2;
            }
        }
        return answer;
    }
}
```