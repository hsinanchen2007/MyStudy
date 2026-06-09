    public int[] getNoZeroIntegers(int n) {
        int[] result = new int[2];
        for (int i = 1; i < n; i++) {
            result[0] = i;
            if (notContainsZero(i) && notContainsZero(n - i)) {
                result[1] = n - i;
                return result;
            }
        }

        return result;
    }

    private boolean notContainsZero(int num) {
        return !String.valueOf(num).contains("0");
    }