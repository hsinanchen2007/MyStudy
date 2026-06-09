![2020021501.PNG](https://pic.leetcode-cn.com/2e701d5473630b07c2fa2c6bfaa69cf26a52a59723fc71b34913d9e42d23c0b8-2020021501.PNG)

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        //使用subString(begin , end)内置方法
        //耗时0ms,击败:100.00%
        //内存消耗:36.9MB,击败:100.00%用户;
    	String st1 = s.substring(0, n);
    	String st2 = s.substring(n, s.length());
    	return st2+st1;
        //使用队列先进先出+遍历一遍字符串
        //耗时:14ms,击败:6.73%用户;
        //内存消耗:45.1MB,击败:100.00%用户;
        // StringBuilder st = new StringBuilder();
        // Deque<Character> rec = new LinkedList<>();
        // for(int i=0;i<s.length();i++){
        //    if(i<n){
        //        rec.push(s.charAt(i));
        //     }else if(i>=n){
        //      st.append(s.charAt(i));
        //  }
        // }
        // while(rec.peekFirst()!=null){
        //     st.append(rec.pollLast());
        // }
        // return st.toString();
    }
}
```