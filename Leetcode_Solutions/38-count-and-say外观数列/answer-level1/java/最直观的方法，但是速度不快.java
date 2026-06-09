1. 看注释就完事了

```
class Solution {
    public String countAndSay(int n) {
        String line = "1";  //初始化第一行
        for (int i = 1; i < n; i++) {
            line = readLine(line);  //每次循环读取之后覆盖前一次的line就行，不用都存下来
        }
        return line;
    }

    private String readLine(String line) {
        int cnt = 1;    //初始化count
        char num = line.charAt(0);  //num是当前count的数字，初始化为第一个数
        String new_line = "";
        for (int i = 1; i < line.length(); i++) {   //从第二个数字开始遍历
            if (line.charAt(i) == num) {
                cnt++;  //当前数字与num相等就cnt++
            } else {    //不相等就把统计好的cnt和num加到新一行当中
                new_line += String.valueOf(cnt) + String.valueOf(num);
                cnt = 1;    //下一个循环重新数数，当然重置cnt
                num = line.charAt(i);   //当然也重置num为当前数字
            }
        }
        new_line += String.valueOf(cnt) + String.valueOf(num);  //别忘了加上最后统计的数字
        return new_line;
    }
}
```
java菜鸟，欢迎指正。
