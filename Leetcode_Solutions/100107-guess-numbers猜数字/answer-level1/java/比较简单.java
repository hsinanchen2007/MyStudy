### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int n = 0; //猜中的个数
        for(int i = 0;i<guess.length;i++){
            if(guess[i]==answer[i]){
                n++;
            }
        }
    return n;
    }
}
```