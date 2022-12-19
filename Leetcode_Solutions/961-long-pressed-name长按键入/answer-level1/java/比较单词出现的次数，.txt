### 解题思路
name和typed出现单词的次数存在list里面，比如alex,aaleex,,,,存在链表里面分别就是nameList 1，1，1，1和
typedList 2，1，2，1  只要nameList.get(i) > typedList 就是错的。
我想到的一个思路就是用栈来解决这个计数问题，，，不过运行时间太慢了，，希望以后的大佬优化

### 代码

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
         List<Integer> list1 = new ArrayList<>();
        Stack<Character> stack = new Stack<>();
        char[] chars1 = name.toCharArray();
        stack.push(chars1[0]);
        for (int i = 1; i < chars1.length; i++) {
            if (stack.peek() == chars1[i]){
                stack.push(chars1[i]);
            }else {
                list1.add(stack.size());
                stack.clear();
                stack.push(chars1[i]);
            }
        }
        if (!stack.isEmpty()){
            list1.add(stack.size());
        }
        List<Integer> list2 = new ArrayList<>();
        Stack<Character> stack2 = new Stack<>();
        char[] chars2 = typed.toCharArray();
        stack2.push(chars2[0]);
        for (int i = 1; i < chars2.length; i++) {
            if (stack2.peek() == chars2[i]){
                stack2.push(chars2[i]);
            }else {
                list2.add(stack2.size());
                stack2.clear();
                stack2.push(chars2[i]);
            }
        }
        if (!stack2.isEmpty()){
            list2.add(stack2.size());
        }
        if (list1.size() != list2.size())
            return false;
        for (int i = 0; i < list1.size(); i++) {
            if (list1.get(i) > list2.get(i))
                return false;
        }
        return true;       
    }
}
```