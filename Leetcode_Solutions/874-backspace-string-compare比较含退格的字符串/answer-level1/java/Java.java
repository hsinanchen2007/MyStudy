### 解题思路
时间O(m+n) 空间O(m+n)

1. 直接stringbuilder操作

2. 两个栈 遇到'#'并且不为空就pop 否则push 最后比较两个栈的内容 全部相同就返回true 否则false

时间O(m+n) 空间O(1)
1. 双指针逆向遍历 两个指针都从末尾元素位置开始 再用两个counter分别保存两个指针各自需要跳过的字符数。进行循环：只要指针位置都合法 把每个指针移到他们分别需要停下的位置： 检查下ij越界没有，比较ij位置字母 不等则不相同 再更新ij越过这个字符

### 代码
双指针
```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skip_s = 0, skip_t = 0;
        while(i >= 0 || j >= 0) {//
            while(i >= 0) {
                if (S.charAt(i) == '#') {skip_s++; i--;}//当前字符#增加需要跳过的字符数
                else if (skip_s > 0) {skip_s--; i--;} //当前字符为字母并且需要跳
                else break;//当前字符为字母且不需要跳(skip_s <= 0)
            }
            while(j >= 0) {
                if (T.charAt(j) == '#') {skip_t++; j--;}
                else if (skip_t > 0) {skip_t--; j--;}
                else break;
            }
            if(i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j)) return false;
            if(i < 0 ^ j < 0) return false; //reach boundary, i or j becomes invalid
            i--; j--;//都小于0 无视
        }
        return true;
    }
}
```

用栈
```
class Solution {

    public boolean backspaceCompare(String S, String T) {
        Stack<Character> st1 = new Stack<>(), st2 = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            char cur = S.charAt(i);
            if(cur != '#') st1.push(cur);
            else if (!st1.isEmpty()) st1.pop();
        }
        for (int i = 0; i < T.length(); i++) {
            char cur = T.charAt(i);
            if(cur != '#') st2.push(cur);
            else if (!st2.isEmpty()) st2.pop();
        }
        Iterator<Character> it1 = st1.iterator(), it2 = st2.iterator();
        boolean flag = st1.size() == st2.size();
        if(!flag) return false;
        while(it1.hasNext() && it2.hasNext()) {
            if(it1.next().equals(it2.next()) == false) return false;
        }
        return true;
    }
}
```

直接操作
```
class Solution {

    public boolean backspaceCompare(String S, String T) {
        StringBuilder s1 = new StringBuilder(), s2 = new StringBuilder();
        // Stack<Character> st = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            char curr = S.charAt(i);
            if(i == 0 && curr == '#') continue;
            if(curr != '#') s1.append(curr);
            else {
                if(s1.length() >= 1) s1.deleteCharAt(s1.length() - 1);
            }
        }
        for (int i = 0; i < T.length(); i++) {
            char curr = T.charAt(i);
            if(i == 0 && curr == '#') continue;
            if(curr != '#') s2.append(curr);
            else {
                if(s2.length() >= 1) s2.deleteCharAt(s2.length() - 1);
            }
        }
        return s1.toString().equals(s2.toString());
    }
}
```

