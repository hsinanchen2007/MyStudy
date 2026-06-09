### 解题思路
循环同一索引位置判断值是否相等

### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int i = 0;
        for(int j=0;j<3;j++){
            if(guess[j]==answer[j]){
                    i++;
            }
        }
        return i;
    }
}
```