入门级的题... 开始下意识以为要双重循环，写着写着发现完全没必要，俩分钟就写完的事儿，所以要先细心省题

```
class Solution {
    public int game(int[] guess, int[] answer) {
        int count = 0;
        for (int a = 0; a < guess.length; a++) {
            if (guess[a] == answer[a]) {
                count++;
            }
        }
        return count;
    }
}

```


