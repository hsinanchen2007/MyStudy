public static int repeatedNTimes(int[] A) {
        int cur = 0;
        while (true) {
            int count = new Random().nextInt(A.length - 1) + 1;
            System.out.println(cur + " " + count);
            if (cur == A.length - 1)
                cur = 0;
            if (A[cur] == A[count] && cur != count)
                return A[cur];
            else
                cur++;
        }
    }