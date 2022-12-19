### 解题思路
注意边界切割即可

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode recoverFromPreorder(String S) {
        if(S == null || S.length() == 0)
            return null;
        StringBuffer stringBuffer = new StringBuffer();
        for(int i=0; i<S.length(); i++){
            if(stringBuffer.length() == 0)
                stringBuffer.append(S.charAt(i));
            else{
                //取出最后一个字符
                char temp = stringBuffer.charAt(stringBuffer.length()-1);
                if(temp == S.charAt(i) || (temp>='0' && temp <= '9' && S.charAt(i) >='0' && S.charAt(i) <='9'))
                    stringBuffer.append(S.charAt(i));
                else {
                    stringBuffer.append("!");
                    stringBuffer.append(S.charAt(i));
                }
            }
        }
        return recoverFromPreorder(stringBuffer.toString(), 0);
    }
      public TreeNode recoverFromPreorder(String S, int level){
        if(S.length() == 0)
            return null;
        //截取第一个数字字符串
        int first_ = S.indexOf('!');
        if(first_ == -1)
            return new TreeNode(Integer.parseInt(S));

        String v = S.substring(0, first_);
        TreeNode root = new TreeNode(Integer.parseInt(v));
        //找中间字符
        String str = "!";
        for(int i=0; i<level+1; i++)
            str += "-";
        str += "!";

        int secondNum = 0;
        for(int i=first_; i<S.length(); i++)
            if(S.charAt(i) >= '0' && S.charAt(i) <= '9'){
                secondNum = i;
                break;
            }
        S = S.substring(secondNum, S.length());

        int mid = S.indexOf(str);
        //如果mid不存在， mid=-1
        if(mid == -1)
            mid = S.length();

        root.left = recoverFromPreorder(S.substring(0, mid), level+1);
        if(mid == S.length())
            root.right = null;
        else
            root.right = recoverFromPreorder(S.substring(mid+level+1+2, S.length()), level+1);
        return root;
    }
}
```