### 解题思路
此处撰写解题思路
有点像爬楼梯，一次可以爬一步或者两步，但是这里的想爬两步是有条件的；只有当chars[i-1] == '1'则chars[i]不管是什么都可以，这时候一步或者两步都行；或者如果chars[i-1] == '2'但是 chars[i]>= '1' && chars[i] <= '6也是满足的，这时候这个位置的方法因该等于dp0 + dp1也即是前一个位置的和前两个位置的；特殊的如果chars[i] == '0'那就需要chars[i-1]要为'1'或者'2'不然就不可能了，这时候的方法等于前两个位置的方法数，因为前一个位置已经被确定了；其他情况表示只能一个位置一个坑，dp1是不变的，dp0变为dp1表示此时的方法种类数依旧是之前的。
'
### 代码

```java
class Solution {
    public int numDecodings(String s) {
        if(s.length() == 0 || s.charAt(0) == '0')
            return 0;
        char[] chars = s.toCharArray();
        int dp0 = 1, dp1 = 1;
        for (int i = 1; i < chars.length; i++){
            int temp = dp1;
            if (chars[i] == '0'){
                if(chars[i-1] == '1' || chars[i-1] == '2')
                    dp1 = dp0;
                else
                    return 0;
            }else if(chars[i-1] == '1' || (chars[i-1] == '2' && chars[i] >= 1 && chars[i] <= '6')){
                dp1 = dp0 + dp1;
            }
            dp0 = temp;
        }
        return dp1;
    }
}
```