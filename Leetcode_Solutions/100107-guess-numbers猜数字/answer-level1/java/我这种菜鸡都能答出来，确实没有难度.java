### 解题思路
我这种菜鸡都能答出来，确实没有难度

### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int t=0;
        for(int i = 0;i<3;i++){
            if(guess[i]==answer[i]){
                t++;
            }
        }
        return t;
    }
}
```