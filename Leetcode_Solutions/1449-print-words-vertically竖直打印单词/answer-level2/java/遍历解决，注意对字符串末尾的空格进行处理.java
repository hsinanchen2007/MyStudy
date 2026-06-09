思路：
（1）首先以 " " 为标准分割字符串 s，得到字符串数组 str，再用 maxl 存储 str 中单词的最大长度；
（2）再根据 maxl 的数值进行遍历，每一位都使用一个 StringBuilder 存储竖直打印的结果（根据实际情况做出相应处理）；
（3）对字符串 sb.toStirng() 进行处理，去除掉末尾的空格，保留其他空格并存储进 list；
（4）返回 list 即为结果。

```
class Solution {
    public List<String> printVertically(String s) {
        List<String> list = new ArrayList<>();
        String[] str = s.split(" ");
        int maxl = 0;
        for(String sp : str){
            maxl = Math.max(maxl,sp.length());
        }  
        for(int i = 0;i < maxl;i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0;j < str.length;j++){
                if(str[j].length() <= i && j == str.length - 1){}
                else if(str[j].length() <= i && j < str.length - 1){
                    sb.append(" ");
                }
                else {
                    sb.append(str[j].charAt(i));
                }
            }
            list.add(calculate(sb.toString()));
        }
        return list;
    }

    public String calculate(String check){
        int real = 0;
        for(int i = 0;i < check.length() - 1;i++){
            if(check.charAt(i) != ' ') break;
            if(check.charAt(i) == ' ' && check.charAt(i + 1) != ' '){
                real = i + 1;break;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int j = 0;j < real;j++) sb.append(" ");
        sb.append(check.trim());
        return sb.toString();
    }
}
```
