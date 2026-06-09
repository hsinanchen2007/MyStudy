如果不存在*的时候，单独考虑(和)两个符号，只需要维护一个变量cnt，用来记录还有多少个左括号可以用来匹配

如果cnt<0，说明能够用来匹配的左括号不够，返回false
如果结束遍历的时候，cnt>0说明有左括号没被匹配，返回false


现在考虑存在*的情况，
1.* 代表空字符串，不对cnt变量造成影响
2.* 代表右括号，cnt-1
3.* 代表左括号，cnt+1
暴力递归上面三种情况即可


```java [java]
class Solution {
    public boolean checkValidString(String s) {
             
        return check(s.toCharArray(),0,0);
    }
    
    boolean check(char[] chs, int start,int open) {
        
        //左括号不够右括号匹配
        if (open < 0) {
            return false;
        }
        
        if (start == chs.length) {
            //遍历到末尾，所有的左括号被匹配
            if (open == 0) {
                return true;
            } else {
                //有剩余左括号没有被匹配
                return false;
            }
        }
        
        if (chs[start] == '(') {
            return check(chs,start+1,open+1);
        } else if (chs[start] == '*') {
            //分别代表上面的1、2、3三种情况
            return check(chs,start+1,open) || check(chs,start+1,open-1) || check(chs,start+1,open+1);
        } else {
            if (open < 1) {
                return false;
            }
            return check(chs,start+1,open-1);
        }
    }
}
```
