```
class Solution {
    public int lengthOfLastWord(String s) {
        // 记录之前可能存在的结果
        int res = 0;
        // 记录当前的结果
        int sum = 0;
        for(char c : s.toCharArray()) {
            if(c == ' ') {
                // 这里如果出现连续的 " "
                // 那么 res 的值不变, 记录的还是上一个单词的长度
                res = sum == 0 ? res : sum;
                sum = 0;
            } else {
                sum++;
            }
        }
        // 如果 sum 为0, 表示String是以空格结尾的, 所以返回上一个单词长度
        return sum == 0 ? res : sum;
    }
}
```
