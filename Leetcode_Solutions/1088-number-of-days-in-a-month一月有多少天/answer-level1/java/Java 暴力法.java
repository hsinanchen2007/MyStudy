```
class Solution {
    public int numberOfDays(int Y, int M) {
        int[] big = new int[]{1,3,5,7,8,10,12};
        int[] small = new int[]{4,6,9,11};
        if(isBig(big, M)) {
            return 31;
        } else if (isSmall(small, M)) {
            return 30;
        } else if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 100 == 0 && Y % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
        
    }
    
    public static boolean isBig(int[] big, int M) {
        for (int i : big) {
            if (i == M) {
                return true;
            }
        }
        return false;
    }
    
    public static boolean isSmall(int[] small, int M) {
        for (int i : small) {
            if (i == M) {
                return true;
            }
        }
        return false;
    }
}
```
