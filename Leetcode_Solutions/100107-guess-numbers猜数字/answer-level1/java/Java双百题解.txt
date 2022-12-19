![屏幕快照 2019-12-01 上午10.21.28.png](https://pic.leetcode-cn.com/58c44caffd770de55fa4b8fa5355b7b036cf2ef24ab4c0edb5537d17d1b2ac93-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-01%20%E4%B8%8A%E5%8D%8810.21.28.png)

```
class Solution {
    public int game(int[] guess, int[] answer) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            if (guess[i] == answer[i]){
                sum++;
            }
        }
        return sum;
    }
}
```
