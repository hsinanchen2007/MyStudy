
    public boolean canMeasureWater(int x, int y, int z) {
        if (z == 0) {
            return true;
        }        
        if (x + y < z) {
            return false;
        }
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        if (y >0) {
            int r = x % y;
            while (r > 0) {
                x = y;
                y = r;
                r = x % y;
            }
            return z % y == 0;
        }
        return z % x == 0;
    }

