
看到整数序列之后原来的思路是想通过List来模拟队列实现，后来发现初始计数比较困难就改用计数和索引实现。

![1573112275(1).jpg](https://pic.leetcode-cn.com/f6dccd46106bc40a0d670c9e9e16cff124c3a74ec3abfd8bc5589cbab024ee87-1573112275\(1\).jpg)

代码与思路如下：

```
public String countAndSay(int n) {
       //初始为1
       String init = "1";
       //执行n次获得第n次报数
        for (int i = 1; i < n; i++) {
            init = parseSring(init);
        }
        return init;
    }
    private String parseSring(String init) {
        //将字符串转换为字符数组用于遍历
        char[] chars = init.toCharArray();
        //建立StringBuilder用于拼接字符串
        StringBuilder sb = new StringBuilder();
        //初始化索引、计数
        //这里的字符最少也会出现1
        int index = 0,num = 1;
        //开始遍历
        while (index<init.length()){
            //将相同且连续的字符统计出来
            //只有两种情况会中断连续：1.这个字符已经是lastChar 2.下一个字符与自身不相同
            if (index==init.length()-1||chars[index+1]!=chars[index]){
                //中断之后将计数与字符放入StringBuilder
                sb.append(num).append(chars[index]);
                //还原计数
                num=1;
                //下一个字符
                index++;
            }else {
                //字符相同且连续，增加计数并指向下一个字符
                num++;
                index++;
            }
        }
        return sb.toString();
    }
```
