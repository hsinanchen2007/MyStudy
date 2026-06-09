### 解题思路
虽然有一些长，但是应该属于正常思路，前半段顺序压入栈，然后不断提取栈内元素，并与后半段顺序比较，思路有点类似于LC20（有效的括号）。
不同之处在于输入的字符串长度可能为奇数，所以需要预先处理一下字符串长度为奇数或等于1的情况，进而进行通用的入栈出栈判断

### 代码

```java
class Solution {
    public boolean isStrobogrammatic(String num) {
        if(num.length()%2!=0) {
            int mid=num.length()/2;
            if(num.charAt(mid)!='0' && num.charAt(mid)!='1' && num.charAt(mid)!='8') {
                return false;
            }
            if(num.length()==1) {
                return true;
            }
            num=num.substring(0, mid)+num.substring(mid+1, num.length());
        }
        return helper(num);
    }

    public boolean helper(String s) {
        LinkedList<Character> stack=new LinkedList<Character>();
        for(int i=0; i<s.length()/2; i++) {
            if(s.charAt(i)=='0') {
                stack.push('0');
            }
            else if(s.charAt(i)=='1') {
                stack.push('1');
            }
            else if(s.charAt(i)=='8') {
                stack.push('8');
            }
            else if(s.charAt(i)=='6') {
                stack.push('9');
            }
            else if(s.charAt(i)=='9') {
                stack.push('6');
            }
            else {
                return false;
            }
        }
        for(int i=s.length()/2; i<s.length(); i++) {
            if(s.charAt(i)!=stack.pop()) {
                return false;
            }
        }
        return stack.isEmpty();
    }
}
```