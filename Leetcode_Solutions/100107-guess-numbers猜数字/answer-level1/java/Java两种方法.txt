# 1. for循环
```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int count = 0;
        for(int i=0;i<guess.length;i++) {
            if(guess[i]==answer[i]) {
                count++;
            }
        }
        return count;
    }
}
```
# 2. if
```java
class Solution {
    public int game(int[] guess, int[] answer) {
        return (guess[0]==answer[0] ? 1: 0) + (guess[1]==answer[1] ? 1: 0) + (guess[2]==answer[2] ? 1: 0);
    }
}
```