### 解题思路
题目场景简化 
因为要先从小到大输出 再从大到小输出  所以要考虑排序 由于有重复数据，可以参考桶排序的实现
把字母的int值 作为桶数组的下标 每出现一次这个字母，对应位置数量加1
由此简化为先从小到大遍历桶数组中的数据，再从大到小遍历桶数组中的数据，
每找到一个对应桶的数量减去1，拼接字符串的长度加1
直到拼接字符串长度和原来的字符串长度相等
### 代码

```java
class Solution {
    public static String sortString (String s){
        //字符串转数组常用
        char[] cs = s.toCharArray();
        //用来统计数量  类似桶排序
        int[] count = new int[256];
        for (char c : cs){
            //char 自动转 int 每次访问这个下标 数量加1
            count[c]++;
        }
        StringBuilder sb = new StringBuilder();
        //字符串长度
        int length = cs.length;
        int c = 0;
        while (c < length) {
            for (int i = 0; i < 256; i++) {
                //从第一个下标开始访问 不等于0说明有数据 从小到大 
                if (count[i] != 0) {
                    count[i]--;
                    sb.append((char) i);
                    //代表已经拼接的一个字符
                    c++;
                }
            }
            //然后反转 从大到小
            for (int i = 255; i >= 0; i--) {
                if (count[i] != 0) {
                    count[i]--;
                    sb.append((char) i);
                    c++;
                }
            }
        }
        return sb.toString();
    }
}
```