### 解题思路
不要频繁的new string，效率低，StringBuffer(),默认好像像是16大小，底层也是new char数组

击败100%用户
### 代码

```java
class Solution {
    public String replaceSpace(String s) {

        // String res = "%20";
        // String ans = "";
        // for (int i = 0; i < s.length(); i++) {
        //     if(s.charAt(i) == ' '){
        //         ans += res;
        //     }else{
        //         ans += (s.charAt(i));
        //     }
        // }
        // return ans;
        String res = "%20";
        StringBuffer ans = new StringBuffer(1000);

        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == ' '){
                ans.append(res);
            }else{
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
```