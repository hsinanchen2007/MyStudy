此题类似于[面试题 01.06. 字符串压缩](https://leetcode-cn.com/problems/compress-string-lcci/)

1. 一般思路，当字符发生变化时记入上一次的字符以及统计的个数，同时统计的个数重置。字符不发生变化继续累加统计的个数。
当扫描到达尾部，再将最后的字符添加上即可。
2. 也可使用快慢指针进行个数统计，当字符发生变化时，计算个数，同时改变快慢指针。

一般思路的核心代码：
```
int i = 1;
int count = 1;
StringBuilder sb = new StringBuilder();
while( i < str.length()){
    if(pre.charAt(i) != str.charAt(i-1)){
        sb.append(count).append(str.charAt(i-1));
        count = 1;
    }else{
        count++;
    }
    i++;
}
sb.append(count).append(str.charAt(i-1));
```

**递归方式代码：**
```
class Solution {
    public String countAndSay(int n) {
        if( n == 1) return "1";
        String pre = countAndSay(n-1);
        int i = 1;
        int count = 1;
        StringBuilder sb = new StringBuilder();
        while( i < pre.length()){
            if(pre.charAt(i) != pre.charAt(i-1)){
                sb.append(count).append(pre.charAt(i-1));
                count = 1;
            }else{
                count++;
            }
            i++;
        }
        sb.append(count).append(pre.charAt(i-1));
        return sb.toString();
    }
}
```

**迭代方式代码：**
```
class Solution {
    public String countAndSay(int n) {
        String pre = "1";        
        for(int i=1;i<n;i++){
           StringBuffer sb = new StringBuffer("");
            int pre_len = pre.length();
            int count = 1;
            char c = pre.charAt(0);
            for(int j=1;j<pre_len;j++){
                if(pre.charAt(j)==c){
                    count++;
                }else{
                    sb.append(count).append(c);
                    c = pre.charAt(j);
                    count = 1;
                }
            }
            pre = sb.append(count).append(c).toString();
        }
        return pre;
    }
}
```


