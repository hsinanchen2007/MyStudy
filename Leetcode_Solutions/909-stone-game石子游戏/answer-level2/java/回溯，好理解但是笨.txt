class Solution {
    public boolean stoneGame(int[] piles) {
        return judge(piles, 0, piles.length - 1, 0, 0, true);
    }

    private boolean judge(int[] piles, int left, int right, int yalics, int li, boolean isYalics) {
        if (left > right) {
            return yalics < li;
        }
        if (isYalics) {
            boolean res1 = judge(piles, left + 1, right, yalics + piles[left], li, false);
            if (res1) {
                return res1;
            }
            return judge(piles, left, right - 1, yalics + piles[right], li, false);
        } else {
            boolean res1 = judge(piles, left + 1, right, yalics, li + piles[left], false);
            if (res1) {
                return res1;
            }
            return judge(piles, left, right - 1, yalics, li + piles[right], false);
        }
    }
}