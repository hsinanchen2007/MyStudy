![image.png](https://pic.leetcode-cn.com/fdfdbec55f6e9db0a9d0a9bef8247e7bfc07c687d93f061417c3198ccbe7eeb9-image.png)

public static int[][] multiSearch(String big, String[] smalls) {

        int[][] result = new int[smalls.length][];

        if (big.length() == 0) {
            for (int i = 0; i < smalls.length; i++) {
                result[i] = new int[0];
            }

            return result;
        }

        for (int i = 0; i < smalls.length; i++) {
            List<Integer> positions = getIndex(big, smalls[i]);

            int[] pos = new int[positions.size()];

            for (int k = 0; k < positions.size(); k++) {
                pos[k] = positions.get(k);
            }
            result[i] = pos;
        }

        return result;
    }

    private static List<Integer> getIndex(String big, String small) {
        List<Integer> positions = new ArrayList<>();
        if (small.length() == 0) {
            return positions;
        }
        int pos = 0;

        while (big.indexOf(small, pos) != -1) {

            int idx = big.indexOf(small, pos);
            positions.add(idx);
            pos = idx + 1;

        }

        return positions;

    }
