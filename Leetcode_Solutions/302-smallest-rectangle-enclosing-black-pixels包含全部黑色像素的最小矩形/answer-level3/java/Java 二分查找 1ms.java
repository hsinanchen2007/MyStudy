```
class Solution {
    static int m,n;
    public static int minArea(char[][] image, int x, int y) {
        n = image.length;
        m = image[0].length;
        int length = binarySearch(y, m - 1, '1', false, image) - binarySearch(0, y - 1, '0', false, image);
        int hight = binarySearch(x, n - 1, '1', true, image) - binarySearch(0, x - 1, '0', true, image);
        return (length * hight);
    }
    public static int binarySearch(int start, int end, char target, boolean vertical, char[][] image) {
        while (start < end) {
            int mid = (start + end +1)/2;
            if (searchLine(mid, target, image, vertical)) start = mid; else end = mid - 1;
        }            
        return searchLine(start, target, image, vertical) ? start : (start - 1); 
    }
    public static boolean searchLine(int mid, char target, char[][] image, boolean vertical) {
        boolean ans = (target == '0');
        for (int i = 0; i < (vertical ? m: n); i++) {
            int a = vertical ? mid : i ,b = vertical ? i : mid;
            ans = (target == '1') ? (ans || image[a][b] == target) : (ans && image[a][b] == target);
        }
        return ans;
    }
}
```
