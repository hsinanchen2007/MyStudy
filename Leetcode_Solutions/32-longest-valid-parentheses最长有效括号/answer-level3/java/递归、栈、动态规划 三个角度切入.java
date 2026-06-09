### 解题思路
分享三种思路：递归、栈和动态规划。其中递归只能求解小规模数据，题目设置的测试点会T

### 代码

## recursion 
预处理两端以后，要做的就是判断该字符串是否valid
1. valid的话就返回当前字符串长度
2. 否则的话递归[0...len-2]和[1...len-1]两个子字符串，取最大值即可

```java
class Solution {
    public boolean check(String t) {
        int len = t.length();
        if(len==0) return true;
        if(len==1) return false;
        Stack<Character> s = new Stack<>();
        s.push(t.charAt(0));
        for(int i=1;i<t.length();i++) {
            if(s.empty() && t.charAt(i)==')') return false;
            else if(t.charAt(i)=='(') s.push('(');
            else if(t.charAt(i)==')' && s.peek()=='(') s.pop();
        }
        return s.empty();
    }
    public int longestValidParentheses(String s) {
        // 预处理
        int len = s.length();
        while(len>1 && s.charAt(0) == ')') {
            s=s.substring(1);
            len = s.length();
        }
        len = s.length();
        while(len>1 && s.charAt(len-1)=='(') {
            s=s.substring(0,len-1);
            len = s.length();
        }
        if(len==0 || len==1) return 0;

        // recursion
        if(check(s)) {
            return len;
        } else {
            return Math.max(longestValidParentheses(s.substring(1)),longestValidParentheses(s.substring(0,len-1)));
        }
    }
}
```

## dp 
dp思路应该和大伙儿差不多。。

```java
    public int longestValidParentheses(String s) {
        // dp[i]: longestValidParentheses end at pos i
        int len = s.length();
        int dp[] = new int[len];
        int res=0;
        for(int i=0;i<len;i++) {
            if(s.charAt(i)=='(') dp[i]=0; // can't end with '('
            else {
                if(i==0) dp[i]=0;
                // condition 1: ...()
                else if(s.charAt(i-1)=='(') {
                    if(i==1) dp[i]=2;
                    else dp[i]=dp[i-2]+2;
                }
                // condition 2: ((...))
                else {
                    if(i-dp[i-1]-1>=0 && s.charAt(i-dp[i-1]-1)=='(') {
                        dp[i]=dp[i-1]+2;
                        if(i-dp[i-1]-2>=0) dp[i]+=dp[i-dp[i-1]-2];
                    } 
                    else dp[i]=0;
                }
            }
            // System.out.println(dp[i]);
            res=Math.max(res, dp[i]);
        }
        return res;
    }
```

## stack
栈存的是每一个字符的位置，通过栈消去匹配的括号，那么通过栈中剩下字符的位置就可以计算出消去括号字符串的长度，取最长即可。

```java
    // stack method
    public int longestValidParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        int res=0;
        int len = s.length();
        st.push(-1);
        for(int i=0;i<len;i++) {
            Character ch = s.charAt(i);
            if(ch=='(') st.push(i);
            else {
                if(st.peek()!=-1 && s.charAt(st.peek())=='(') {
                    st.pop();
                }else st.push(i);
            }
        }
        st.push(len);
        int pre = st.pop();
        while(true) {
            if(st.empty()){
                if(pre==1) pre=0;
                res=Math.max(res, pre);
                break;
            } else {
                res=Math.max(res, pre-st.peek()-1);
                pre=st.pop();
            }
        }
        return res;
    }
```