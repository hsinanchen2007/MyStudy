# 递归
从模式串p的角度考虑！！！
1. 当p为空，则s为空，则为true；
2. p不为空，则s也不应为空，true的条件：
            条件1 s.length() > 0;
            条件2 s.charAt(0) == p.charAt(0) **或者** p.charAt(0) == '.'
3. p长度至少为2，且第二个元素为 * 
            *可以表示0个或多个前面的元素
            条件3：当*表示0个前面的元素的时候，递归调用isMatch(s, p.substring(2))
            条件4：当*表示多个前面的元素的时候，递归调用isMatch(s.substring(1), p))，同时此时必须满足match=true，即首个字符要匹配
4. p长度为1，必须满足条件1以及条件2，此时递归调用isMatch(s.substring(1), p.substring(1))
5. p的长度大于1，且第二个元素不为 *
   必须满足条件1以及条件2，此时递归调用isMatch(s.substring(1), p.substring(1))
```java
    public boolean isMatch(String s, String p) {
        //p为空串
        if(p.isEmpty()){
            return s.isEmpty();//s也为空，则返回true
        }
        //p不为空串，s则要求其不为空，s.charAt(0) == p.charAt(0)或者p.charAt(0) == '.'
        boolean match = (s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.'));
        //如果p的长度大于1，且p的第二个字符为*
	    if (p.length() > 1 && p.charAt(1) == '*'){
            //*可以表示0个或多个前面的元素
            //当*表示0个前面的元素的时候，递归调用isMatch(s, p.substring(2))
            //当*表示多个前面的元素的时候，递归调用isMatch(s.substring(1), p))，同时此时必须满足match=true，即首个字符要匹配
	        return isMatch(s, p.substring(2)) || (match && isMatch(s.substring(1), p));
	    } else {
            //p的长度为1或者p的第二个字符不是*
	        return match && isMatch(s.substring(1), p.substring(1));
	    }
    }
```
