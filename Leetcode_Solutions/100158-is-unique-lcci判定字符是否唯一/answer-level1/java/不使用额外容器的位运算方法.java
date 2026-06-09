### 解题思路
思路和解释都写的很清楚了，请参考下方代码

### 代码

```java
class Solution {
    // 使用bit运算也可以有相同的效果
    // 只要该位变为1，那么就证明有数字了
    public boolean isUnique(String astr) {
        // 放26个英文字母的
        // 从a开始计算，倒着，a在最后1位，z在第一位
        int bits = 0b00_00000000_00000000_00000000;
        char[] sub = astr.toCharArray();
        for(int i=0;i<sub.length;i++){
            char c = sub[i];
            // 这是当前字符的偏移量
            // 比如a就是0，b就是1
            int offset = c - 97;

            // 要检查该位置的变量在bits中是0还是1
            int valueOfBits = (bits >> offset) & 1;
            if(valueOfBits == 1){
                return false;
            }
            bits = bits | (1 << offset);
        }
        return true;
    }
}
```