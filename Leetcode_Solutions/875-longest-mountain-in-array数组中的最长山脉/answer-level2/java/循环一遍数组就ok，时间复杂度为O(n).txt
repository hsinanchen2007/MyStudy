```
public class Solution {
    public int longestMountain(int[] A) {

        int i = 0 , j = A.length-1, res = 0, t = 0;
        while (i < A.length-1) {
            int i1 = goUp(A, i);
            int i2 = goDown(A, i1);
            if (i1 != i && i2 != i1) { // 出现波峰
                res = Math.max(res, i2-i+1);
            }
            i = goSmooth(A, i2);
        }
        return res;
    }

    // 下坡
    private int goDown(int[] a, int i){
        while (i+1 < a.length && a[i] > a[i+1]) ++i;
        return i;
    }
    // 爬高
    private int goUp(int[] a, int i){
        while (i+1 < a.length && a[i] < a[i+1]) ++i;
        return i;
    }
    // 平坦
    private int goSmooth(int[] a, int i){
        while (i+1 < a.length && a[i] == a[i+1]) ++i;
        return i;
    }

    public static void main(String[] args) {
        int i = new Solution().longestMountain(new int[]{2,2,2});
        System.out.println("i = " + i);
    }
}
```
