### 解题思路
方法1：用时2ms
当n=2,字符串更新了1次；n=3,字符串更新了2次；n=4，字符串更新了3次。
双重循环暴力求解：外层循环表示更新的次数，内层表示一次更新后的结果。
参考链接：https://leetcode-cn.com/problems/count-and-say/solution/yyxue-xi-bi-ji-21-by-yang-yang-yang-73/
方法2：用时3ms
递归求解，当前n对应的字符串需要求解n-1对应的字符串

### 代码

```java
//双重循环
class Solution {
    public String countAndSay(int n) {
        String str = "1";
        //n=1时，直接返回
        //字符串更新的次数为n-1;
        for(int j = 2; j <= n; j ++){
            StringBuilder tmp = new StringBuilder();
            char pre = str.charAt(0);
            int cnt = 1;
            //计算每一次更新得到的字符串
            //若n≠1，则对应初始条件str=“1”，需要进入n=2
            for(int i = 1; i < str.length(); i ++){
                char cur = str.charAt(i);
                if(cur == pre){
                    cnt ++;
                }else{
                    tmp.append(cnt).append(pre);
                    pre = cur;
                    cnt = 1;
                }
            }
            //添加最后一位的值
            tmp.append(cnt).append(pre);
            str = tmp.toString();
        }
        return str;  
    }
}
```
```java
//递归
class Solution {
    public String countAndSay(int n) {
           return digui(n, "1");
    }   
    public String digui(int n, String s){
        if(n == 1){
            return s;
        }
        String str = digui(n-1, s);
        StringBuilder res = new StringBuilder();
        char pre = str.charAt(0);
        int cnt = 1;
        for(int i = 1; i < str.length(); i ++){
            char cur =str.charAt(i);
            if(cur == pre){
                cnt ++;
            }else{
                res.append(cnt).append(pre);
                pre = cur;
                cnt = 1;
            }
        }
        res.append(cnt).append(pre);
        return res.toString();
        //如果想最后return，注意return digui(--n, res.toString());
    }
}
```