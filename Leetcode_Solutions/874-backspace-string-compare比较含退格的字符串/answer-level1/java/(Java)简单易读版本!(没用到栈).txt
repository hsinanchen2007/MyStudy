**简单思路就是用charAt()倒着取出S和T中的字符，每次取出时进行判断：**
**1. 碰到'#'将count++(count代表前面要进行退格的字符数)，跳出本次循环**
**2. 非1情况下count大于0时（代表有退格情况），将count--，跳出本次循环（代表退格）。**
**3. 非1、2情况下正常将字符取出放到StringBuilder SS和TT中**

**然后将字符串比较，其实取出的是倒序顺序的字符串，但是两个都是倒序跟两个都正序的比较结果都一样，也就没有把两个字符串都倒过来。**
**代码如下：**
```
class Solution {
    public boolean backspaceCompare(String S, String T) {
        StringBuilder SS = new StringBuilder();
        StringBuilder TT = new StringBuilder();
        int count=0;
        for(int i=S.length()-1;i>=0;i--){
            char t = S.charAt(i);
            if(t=='#'){
                count++;
                continue;
            }
            if(count>0){
                count--;
                continue;
            }else{
                SS.append(t);
            }
        }
        count=0;
        for(int i=T.length()-1;i>=0;i--){
            char t = T.charAt(i);
            if(t=='#'){
                count++;
                continue;
            }
            if(count>0){
                count--;
                continue;
            }else{
                TT.append(t);
            }
        }
        if(SS.toString().equals(TT.toString())){
            return true;
        }else
            return false;
    }
}
```
