此答案来源于`vscode-leetcode`插件给出的题解，我只是和大家分享我对此解法的理解，希望能帮助到大家
```
class Solution {
    public String toHex(int num) {
        // 根据十进制的索引获取对应十六进制的表示
        char[] map = new char[] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        int mask = 0b1111;// == 0xf
        StringBuilder sb = new StringBuilder();
        // 取高四位，紧接着次高四位……
        for (int i = 28; i >=0; i -= 4) {
            // (num >> i) 移除低位，取高四位
            // (num >> i) & mask 将高四位的二进制转换成对应的十进制
            int index = ((num >> i) & mask);
            if ((sb.length() == 0)) {
                if (index != 0) {
                    // map[index] 根据十进制索引获取对应十六进制的表示（十进制转换成十六进制）
                    sb.append(map[index]);
                }
            } else {
                sb.append(map[index]);
            }
        }
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
```
