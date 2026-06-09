若N为偶数，则爱丽丝说1使其变为奇数给到鲍勃，由于奇数的因数必为奇数，给到爱丽丝的数必为偶数，到2时即可获胜。
若N为奇数，则给到鲍勃必为偶数，同理鲍勃必赢。
```
class Solution {
    public boolean divisorGame(int N) {
        return N % 2 == 0;
    }
}
```
