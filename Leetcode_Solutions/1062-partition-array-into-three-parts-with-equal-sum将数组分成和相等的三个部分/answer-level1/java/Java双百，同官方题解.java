    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        int indexi = 0;
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
        }
        if (sum % 3 != 0) {
            return false;
        }
// 下面的两个循环可以合并，觉得麻烦就没改了，有兴趣的自行尝试
        for (int i = 0, temp = 0; i < A.length; i++) {
            temp += A[i];
            if (temp == sum / 3) {
                indexi = i;
                break;
            }
        }
        for (int i = indexi+1, temp = 0; i < A.length-1; i++) {
            temp += A[i];
            if (temp == sum / 3) {
                return true;
            }
        }
        return false;
    }