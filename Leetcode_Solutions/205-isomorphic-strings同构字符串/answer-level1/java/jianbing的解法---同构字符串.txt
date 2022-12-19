执行用时 :4 ms, 在所有 Java 提交中击败了98.63% 的用户
内存消耗 :38.3 MB, 在所有 Java 提交中击败了38.97%的用户
代码很短很清晰，思路是这样的：
我先搞一个127（开始我用的是26来代替26个字母，结果发现可以有数字，干脆一点用127了）长度的数组，其中每个元素是长度为2的小数组，其中0号元素表示这个字符有没有被别人用来当做映射目标，1号元素表示这个字符要映射的目标；
遍历一波，如果发现不对直接返回失败
代码如下：
```
class Solution {
    public boolean isIsomorphic(String s, String t) {
        int [][] flag=new int[127][2];//第一维127个格子代表127个字符，
        char[] chars = s.toCharArray();// 第二维，0号元素代表有没有被替换使用，
        char[] chart = t.toCharArray();// 1号元素代表使用哪个元素进行替换
        for (int i = 0; i <chars.length; i++) {
            if (flag[chars[i]-'\0'][1]==chart[i]-'\0')continue;//已经映射成功的
            else if (flag[chart[i]-'\0'][0]==0&&flag[chars[i]-'\0'][1]==0){//暂未映射
                flag[chart[i]-'\0'][0]=1;//标记这个字母已用
                flag[chars[i]-'\0'][1]=chart[i]-'\0';//并且形成映射
            }
            else return false;
        }
        return true;
    }
}
```
