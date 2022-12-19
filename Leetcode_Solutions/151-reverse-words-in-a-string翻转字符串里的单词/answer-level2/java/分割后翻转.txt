### 代码

```java
class Solution {
    public String reverseWords(String s) {
        //如果字符串长度为0，直接返回
        if(s.length() == 0)
        return s;
        //去除首位空格
        s = s.trim();
        //根据空格将字符串分割，分割结果放进一个字符串数组
        String[] str = s.split(" ");
        //原地翻转
        int left = 0,right = str.length - 1;
        while(left < right){
            String t = str[left];
            str[left] = str[right];
            str[right] = t;
            left ++;
            right --;
        }
        //将字符串数组数据连接得到结果
        StringBuilder res = new StringBuilder();
        for(int i = 0;i < str.length - 1;i ++){
            //当两个字符串中间有多个空格时，分割会得到空的数组，如果是空的，直接跳过不处理
            if(str[i].equals(""))
            continue;
            res.append(str[i]);
            res.append(" ");
        }
        res.append(str[str.length - 1]);
        return res.toString();
    }
}
```