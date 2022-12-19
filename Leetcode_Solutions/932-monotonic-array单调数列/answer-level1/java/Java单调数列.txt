public class MonotonicArray {
    public boolean isMonotonic(int[] A) {

        if (A.length == 0 || A.length == 1 || A.length == 2) {
            return true;
        }

        int countUp = 0;
        for (int i = 1; i < A.length; i ++) {
            if ((A[i] - A[i - 1]) >= 0) {
                countUp ++;
            }
        }
        if (countUp == (A.length - 1)) {
            return true;
        }

        int countDown = 0;
        for (int i = 1; i < A.length; i ++) {
            if ((A[i] - A[i - 1]) <= 0) {
                countDown ++;
            }
        }
        if (countDown == (A.length - 1)) {
            return true;
        }

        return false;
    }
}