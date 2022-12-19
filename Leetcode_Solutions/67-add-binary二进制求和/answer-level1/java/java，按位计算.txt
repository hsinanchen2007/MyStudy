### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        int len1 = a.length();
        int len2 = b.length();
        // 使a始终为比较长的那个数，方便计算
        if(len1 < len2){
            return addBinary(b, a);
        }
        int max = Math.max(len1, len2);
        int j = len2 - 1;
        int tmp = 0;    // tmp记录每一位上相加的和，总共有4种情况：0, 1, 2, 3
        StringBuilder sb = new StringBuilder();
        for(int i = max - 1; i >= 0; i--){
            if(a.charAt(i) == '1'){
                tmp++;
            }
            if(j >= 0 && b.charAt(j--) == '1'){
                tmp++;
            }
            // 若tmp == 1 或tmp == 3
            if(tmp%2 != 0){
                sb.append("1");
            }
            // 若tmp == 0或tmp == 2
            else{
                sb.append("0");
            }
            // tmp == 2或tmp == 3的情况下，需要进1，即进入下轮循环时tmp初始值为1
            tmp = tmp/2;
        }
        // 若最后tmp == 1，表示还需要继续进1位
        if(tmp == 1){
            sb.append("1");
        }
        // 由于每次结果都是追加进去时，第一个追加的其实是最后一位，所以需要反转
        return sb.reverse().toString();
    }
}
```