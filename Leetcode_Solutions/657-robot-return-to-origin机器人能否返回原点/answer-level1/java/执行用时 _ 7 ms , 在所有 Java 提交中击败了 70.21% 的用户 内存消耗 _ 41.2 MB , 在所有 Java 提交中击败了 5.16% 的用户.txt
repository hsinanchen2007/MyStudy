### 解题思路
很简单的题目，机器人不管如何行走，往左必然有一个往右相抵消，没有就必然无法回到原点，上下也是类似，只要不想同就无法抵消，理解这一点只需要统计上下左右的d个数，如果上等于下，左等于右，那么我们就认为机器人可以回到原点，否则不行。

### 代码

```java
class Solution {
    public boolean judgeCircle(String moves) {
        int[] arr = new int[26];
        for(int i = 0;i<moves.length();i++) {
            arr[moves.charAt(i)-'A']++;
        }
        if(arr['R'-'A']==arr['L'-'A'] && arr['U'-'A']==arr['D'-'A'] ) {
            return true;
        } 
        return false;
    }
}
```