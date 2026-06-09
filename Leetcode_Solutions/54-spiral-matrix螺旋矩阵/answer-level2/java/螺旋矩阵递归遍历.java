    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return res;
        spiralOrderRecur(res, matrix, 0);
        return res;
    }
    private void spiralOrderRecur(List<Integer> res, int[][] matrix, int pos) {
        int m = matrix.length, n = matrix[0].length;
        for (int col = pos; col < n - pos; col++) res.add(matrix[pos][col]);
        for (int row = pos + 1; row < m - pos; row++) res.add(matrix[row][n - pos - 1]);
        if (m - pos - 1 != pos) {
            for (int col = n - pos - 2; col >= pos; col--) res.add(matrix[m - pos - 1][col]);
        }
        if (pos != n - pos - 1) {
            for (int row = m - pos - 2; row > pos; row--) res.add(matrix[row][pos]);
        }
        int visited = (pos + 1) * 2;
        if (m > visited && n > visited) spiralOrderRecur(res, matrix, pos + 1);
    }