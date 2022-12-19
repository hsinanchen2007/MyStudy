    public String reverseStr(String s, int k) {
        int lastCnt = s.length() % (2 * k);
        int num = s.length() / (2 * k);
        char[] chs = s.toCharArray();
        for (int i = 1; i <= 2 * num; i += 2) {
            int low = (i - 1) * k;
            int high = i * k - 1;
            System.out.println("low:" + low + ", high:" + high);
            reverseChar(chs, low, high);
        }

        if (lastCnt > k) {
            // reverse k
            reverseChar(chs, 2 * k * num, 2 * k * num + k - 1);
        } else {
            // reverse all
            reverseChar(chs, 2 * k * num, chs.length - 1);
        }
        return new String(chs);
    }

    public void reverseChar(char[] chs, int low, int high) {
        while (low < high) {
            char temp = chs[low];
            chs[low++] = chs[high];
            chs[high--] = temp;
        }
    }