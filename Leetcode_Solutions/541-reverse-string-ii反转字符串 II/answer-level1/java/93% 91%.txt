### 解题思路
![微信图片_20200209113918.png](https://pic.leetcode-cn.com/5ea2c3ddee50b148c1afbca4e8b01f98a1b23752fb938840b3b75e66b271a0f3-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200209113918.png)
暴力解法，每隔k个数操作一次，奇数次翻转，偶数次跳过。
在翻转操作中，分两种情况，一种是长度为k，一个是不到k就到结尾了。

### 代码

```java
class Solution {
    public String reverseStr(String s, int k) {
        int i=0;
        char[] ch=s.toCharArray();
        while(i<ch.length){
            if (i%(2*k)==0){
                if (i+k-1<ch.length) {
                    for (int j = 0; j < k / 2; j++) {
                        char mid = ch[i + j];
                        ch[i + j]=ch[i+k-1-j];
                        ch[i+k-1-j]=mid;
                    }
                }
                else{
                    for (int j = 0; j < (ch.length-i)/2; j++) {
                        char mid = ch[i + j];
                        ch[i + j]=ch[ch.length-1-j];
                        ch[ch.length-1-j]=mid;
                    }
                }
            }
            i+=k;
        }
        return new String(ch);
    }
}
```