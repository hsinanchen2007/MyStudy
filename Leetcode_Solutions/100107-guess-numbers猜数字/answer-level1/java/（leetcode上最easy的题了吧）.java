```java []
class Solution {
    public int game(int[] guess, int[] answer) {
        int ans = 0;
        for(int i = 0;i < 3;i++) if(guess[i] == answer[i]) ans++;
        return ans;
    }
}
```
```go []
func game(guess []int, answer []int) int {
    ans := 0

    for i := 0;i < 3;i++ {
        if guess[i] == answer[i] {
            ans++
        }
    }

    return ans
}
```

