思路：直接遍历，遇到#就删除前一个字符和当前的#，然后重新遍历，灵性-1，希望大家能发现-1的妙用(*^▽^*)。
<br/><br/>
代码：
```
class Solution {
    public boolean backspaceCompare(String S, String T) {
        StringBuilder sb = new StringBuilder(S);
        deal(sb);
        
        StringBuilder tb = new StringBuilder(T);
        deal(tb);
        
        return sb.toString().contentEquals(tb);
    }
    
    private void deal(StringBuilder s) {
        for (int i = 0;i < s.length();i++) {
            if (s.charAt(i) == '#') {
                s.deleteCharAt(i);
                if (i - 1 >= 0) {
                    s.deleteCharAt(i - 1);
                }
                
                i = -1;// 这个-1很有灵性
            }
        }
    }
}
```

![image.png](https://pic.leetcode-cn.com/12f29ba9f0925d43cdbd5f14b9518d929241201933f60a1b21a642fc38cc3880-image.png)