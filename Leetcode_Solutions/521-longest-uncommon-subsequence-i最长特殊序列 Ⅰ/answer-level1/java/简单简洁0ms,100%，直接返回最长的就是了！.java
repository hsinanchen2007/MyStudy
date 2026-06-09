![image.png](https://pic.leetcode-cn.com/b9a70c9f003bf312c38739bd2c790fe21f47e648291176d31c9ec05676768764-image.png)

```
class Solution {
    public int findLUSlength(String a, String b) {
        if (a.equals(b))return -1;
        
        String LenStr = a.length()>b.length()?a:b;
        String ShoStr = a.length()<b.length()?a:b;
        
        return LenStr.length();

    }
}
```
