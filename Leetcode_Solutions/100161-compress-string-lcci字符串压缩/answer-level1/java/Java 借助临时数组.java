### 解题思路
此处撰写解题思路
复杂度O(n)
利用一个数组存放重复的数字
![image.png](https://pic.leetcode-cn.com/dabb556e3c63e057458499ba19db373760acb13edd9c842f9504f7f950deef83-image.png)

### 代码

```java
class Solution {
    public String compressString(String S) {
        if (S == null || S.equals("")){
            return "";
        }
        int len = S.length();
        int[] temp = new int[len];
        temp[0] = 1;
        char last = S.charAt(0);
        for (int i = 1; i < len; i++) {
            if (S.charAt(i) != last){
                temp[i] = 1;
            }else {
                temp[i] = temp[i-1]+1;
            }
            last = S.charAt(i);
        }
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append(String.valueOf(S.charAt(0)));
        last = S.charAt(0);
        for (int i = 1; i < len; i++) {
            if (S.charAt(i) != last){
                stringBuffer.append(temp[i-1]).append(String.valueOf(S.charAt(i)));

            }
            last = S.charAt(i);
        }
        stringBuffer.append(temp[len-1]);
        String res = stringBuffer.toString();
        return res.length() < S.length() ? res : S ;
    }
}
```