执行用时 :3 ms, 在所有 Java 提交中击败了90.36% 的用户 
内存消耗 :34.2 MB, 在所有 Java 提交中击败了90.32%的用户
```
class Solution {
    public String countAndSay(int n) {
        StringBuilder sb = new StringBuilder();
        //把1追加进去
        sb.append(1);
        n--;
        while (n > 0) {
            //每一行的字符串(后来读题发现只要输出某一行的，而不是所有的)
            StringBuilder sbTemp = new StringBuilder();
            for (int i = 0, len = sb.length(); i < len; i++) {
                int j = i;
                //计数有几个相同的字符
                int count = 0;
                //双指针的后指针往后位移并且如果与第一个指针的字符相等则继续位移且计数
                while (j < len && sb.charAt(j) == sb.charAt(i)) {
                    j++;
                    count++;
                }
                // 记录 计数+字符 表示 几个什么字符
                sbTemp.append(count).append(sb.charAt(i));
                // 位移第一个指针，(因为表达式3有个i++,所以这里不是i = j ,而是 i = j - 1)
                i = j - 1;
            }
            n--;
            // 将该行的字符串赋值给sb,让下一次循环遍历该行
            sb = sbTemp;
        }
        
        return sb.toString();
    }
}
```
这个题吧，做的... 好几次没读懂题意... 能通过就行..


