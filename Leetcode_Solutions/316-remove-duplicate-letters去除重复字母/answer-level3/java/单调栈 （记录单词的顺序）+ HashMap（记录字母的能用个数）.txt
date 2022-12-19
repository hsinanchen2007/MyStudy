### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String removeDuplicateLetters(String s) {
        if(s.length() < 2){
            return s;
        }
        char[] ss = s.toCharArray();
        //记录当前每个单词的可用个数，当map.get(i) == 0 表示当前可用的该单词个数为零，不能被弹出
        Map<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < s.length(); i++){
            map.put(ss[i], map.getOrDefault(ss[i], 0) + 1);
        }
        //单调栈，用于记录结果单词中字母的顺序
        Stack<Character> stack = new Stack<>();
        //用于记录单调栈中的单词，使用set的查找时间复杂度为O（1）
        Set<Character> set = new HashSet<>();
        for(int i = 0; i < s.length(); i++){
            char c = ss[i];
            //当前栈中已经有了该字母，因此不再放入重复的字母
            if(set.contains(c)){
                //记得要将该字母能用的个数-1，因为此时尽管它没有放入栈中，但是它的“轮次”已经过去，在后面也不会被使用，相当于失效了。
                map.put(c, map.get(c) - 1);
                continue;
            }
            //关键步骤：判断当前栈顶的字母是否大于将要放入的字母。如果大于，并且栈顶的字母的能用个数大于1，则可以弹出。否则（栈顶元素小于将要放入的元素或者栈顶元素能用个数为0），不能。
            while(!stack.isEmpty() && c < stack.peek() && map.get(stack.peek()) > 0){
                
                set.remove(stack.peek());
                stack.pop();
            }
            //执行压栈操作
            stack.push(c);
            //将该字母的能用个数-1
            map.put(c, map.get(c) - 1);
            //记录栈中元素
            set.add(c);
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()){
            sb.append(stack.pop());
        }
        //记得反转字符串
        return sb.reverse().toString();
    }
}
```