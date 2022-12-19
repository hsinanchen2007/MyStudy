```
class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        Arrays.sort(piles);
        if (piles.length > H) return 0;
        if (piles.length == H) return piles[piles.length-1];

        if (piles.length < H) {
            for (int k=1; k<piles[piles.length-1]; k++) {
                long count = 0;
                for (int j=0;j<piles.length;j++) {
                    if (piles[j] % k != 0) {
                        count += piles[j] / k + 1;
                    } else {
                        count += piles[j] / k;
                    }
                }
                if (count <= H) {
                    return k;
                }
            }
        }

        return 0;
    }
}
```