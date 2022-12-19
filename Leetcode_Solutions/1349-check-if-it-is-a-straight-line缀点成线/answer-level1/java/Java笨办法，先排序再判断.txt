
class Solution {
    public static boolean checkStraightLine(int[][] coordinates) {
        sort(coordinates);
        for (int a = 0; a < coordinates.length; a++) {
            System.out.println(coordinates[a][0] + "," + coordinates[a][1]);
        }
        int x = coordinates[1][0] - coordinates[0][0];
        int y = coordinates[1][1] - coordinates[0][1];
        int t = 0;
        if (x != 0 && y != 0) {
            t = y / x;
        }
        for (int i = 0; i < coordinates.length - 1; i++) {
            int m = coordinates[i + 1][0] - coordinates[i][0];
            int n = coordinates[i + 1][1] - coordinates[i][1];
            int s = 0;
            if (m != 0 && n != 0) {
                s = n / m;
            }
            if (t != s) {
                return false;
            }
        }
        return true;
    }

    private static void sort(int[][] coordinates) {
        for (int i = 0; i < coordinates.length; i++) {
            int temp;
            int temp1;
            for (int j = i + 1; j < coordinates.length; j++) {
                if (coordinates[i][0] > coordinates[j][0]) {
                    temp = coordinates[j][0];
                    temp1 = coordinates[j][1];
                    coordinates[j][0] = coordinates[i][0];
                    coordinates[j][1] = coordinates[i][1];
                    coordinates[i][0] = temp;
                    coordinates[i][1] = temp1;
                }
            }
        }
    }
}