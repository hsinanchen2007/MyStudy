package water;

public class Water3D {
    public static void main(String[] args) {
        int[][] water = { //
                {1, 4, 3, 1, 3, 2},//
                {3, 2, 1, 3, 2, 4},//
                {2, 3, 3, 2, 3, 1} //
        };
        int[][][] waterFilled = fullFillWater(water);
        int[][][] waterFlowed = flowWater(waterFilled);
        int count = countWater(waterFlowed);
        System.out.println(count);
    }

    private static int[][][] fullFillWater(int[][] water) {
        int highPoint = getHighPoint(water);
        int[][][] waterFilled = new int[water.length][water[0].length][highPoint];
        for (int x = 0; x < waterFilled.length; x++) {
            for (int y = 0; y < waterFilled[x].length; y++) {
                for (int z = 0; z < waterFilled[x][y].length; z++) {
                    if (z <= water[x][y] - 1) {
                        waterFilled[x][y][z] = 1;
                    } else {
                        waterFilled[x][y][z] = 2;
                    }
                }
            }
        }
        return waterFilled;
    }

    private static int getHighPoint(int[][] water) {
        int highPoint = 0;
        for (int x = 0; x < water.length; x++) {
            for (int y = 0; y < water[x].length; y++) {
                if (highPoint <= water[x][y]) {
                    highPoint = water[x][y];
                }
            }
        }
        return highPoint;
    }

    private static int[][][] flowWater(int[][][] water) {
        for (int x = 0; x < water.length; x++) {
            for (int y = 0; y < water[x].length; y++) {
                for (int z = 0; z < water[x][y].length; z++) {
                    if (isSide(water, x, y)) {
                        if (isWater(water, x, y, z)) {
                            flow(water, x, y, z);
                        }
                    }
                }
            }
        }
        return water;
    }

    private static void flow(int[][][] water, int x, int y, int z) {
        water[x][y][z] = 0;
        flowFourSides(water, x, y, z);
    }

    private static void flowFourSides(int[][][] water, int x, int y, int z) {
        flowOneSide(water, x - 1, y, z);
        flowOneSide(water, x + 1, y, z);
        flowOneSide(water, x, y - 1, z);
        flowOneSide(water, x, y + 1, z);
    }

    private static void flowOneSide(int[][][] water, int x, int y, int z) {
        if (x < 0) {
            ;
        } else if (x > water.length - 1) {
            ;
        } else if (y < 0) {
            ;
        } else if (y > water[0].length - 1) {
            ;
        } else if (isWater(water, x, y, z)) {
            flow(water, x, y, z);
        }
    }

    private static boolean isWater(int[][][] water, int x, int y, int z) {
        return water[x][y][z] == 2;
    }

    private static boolean isSide(int[][][] water, int x, int y) {
        boolean result = false;
        if (x == 0) {
            result = true;
        }
        if (x == water.length - 1) {
            result = true;
        }
        if (y == 0) {
            result = true;
        }
        if (y == water[x].length - 1) {
            result = true;
        }
        return result;
    }

    private static int countWater(int[][][] water) {
        int sum = 0;
        for (int x = 0; x < water.length; x++) {
            for (int y = 0; y < water[x].length; y++) {
                for (int z = 0; z < water[x][y].length; z++) {
                    if (water[x][y][z] == 2) {
                        sum++;
                    }
                }
            }
        }
        return sum;
    }

    private static void printArr3D(int[][][] arr) {
        for (int z = 0; z < arr[0][0].length; z++) {
            for (int x = 0; x < arr.length; x++) {
                for (int y = 0; y < arr[0].length; y++) {
                    System.out.print(arr[x][y][z] + ((y == arr[0].length - 1) ? "" : "_"));
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}
