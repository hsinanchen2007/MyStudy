### 解题思路
利用split把字符串分割，存入String数组，再利用StringBuffer的append方法重新拼接即可。

注意：
1. 如果字符串前面有空格 split() 会产生一个""，如果中间有连续的三个空格 会产生两个""。
2. 使用equals而不用==，因为==比较的是内存地址即是否为同一个对象，equals比较的是内存空间里的内容是否相同。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] res = s.split(" ");
        StringBuffer sb = new StringBuffer();
        for(int i = res.length - 1;i >= 0;i--){
            if(!res[i].equals("")){
                sb.append(res[i]);
                sb.append(" ");
            }
        }
        return sb.toString().trim();
    }
}
```