### 思路

> 此处需要注意,使用该方法需要题目中的一个前提，即字符串中只存在小写字母

例: 有字符串 'abab'

1. 后缀字串 	
  abab、bab、ab、b
2. 非后缀字串 (一定不为字典序的最后一位)
  a、aba、ba
3. 字典序排序结果
a、ab、aba、abab、b、ba、bab
4. 方法
找出字符串中最大的后缀字串即可
首先定义左右字符,判断左字符和右字符的大小
如果左==右,k+1
如果左>右,右+1，即左边为最大字串的起始位，继续向右边寻找有没有比其字典序更大的字符
如果右>左,左+1, 即右边为字典序大的字符，左边位置更新
5. 缺点
无效的k++造成算法时间增加

![思路](https://pic.leetcode-cn.com/4256f4b49315a25fd7b56c132d1c1bbf3f0dd6eb15e54886cda7d55524871bd8-S%7DFOT\)UFOX%5D37JDR9\)_8%5D0W.png)

### 代码

```java
class Solution {
    public String lastSubstring(String s) {
        int n = s.length();
        char[] c = s.toCharArray();
        
        int l = 0, r = 1, k = 0;
        
        while( l < n && r < n && k < n) {
            
            if(c[(l+k)%n] == c[(r+k)%n]) k++;
            else{
                if(c[(l+k)%n] > c[(r+k)%n]) r += (k+1);
                else l += (k+1);
                
                if(l == r) r++;
                k = 0;
            }
        }
        int p = Math.min(l ,r);
        
        return s.substring(p, n);
    }
}
```
