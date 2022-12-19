### 解题思路
先扫描一遍有多少个空格，然后申请原字符串长度+空格数*2大小的char[]，从高向低倒着重置char[]即可

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        if (s==null || s.length()==0) {
            return s;
        }
        char[] data = s.toCharArray();
        int cnt = 0;
        for (int i=0; i<data.length; i++) {
            if (data[i] == ' ') {
                cnt++;
            }
        }
        char[] res = new char[data.length+cnt*2];
        int lo = data.length-1;
        int hi = res.length-1;
        while (lo>=0) {
            if (data[lo]==' ') {
                res[hi--] = '0';
                res[hi--] = '2';
                res[hi--] = '%';
            }
            else {
                res[hi--] = data[lo];
            }
            lo--;
        }
        return new String(res);
    }
}
```