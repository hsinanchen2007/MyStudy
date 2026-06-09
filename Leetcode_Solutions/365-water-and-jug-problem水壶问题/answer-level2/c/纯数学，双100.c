bool canMeasureWater(int x, int y, int z){
    /* mx + ny = z */
    if(x==0 && y==0) {
        return z == 0;
    }
    if (z == 0) {
        return true;
    }
    if((x + y) < z) {
        return false;
    }

    while(x % y != 0){
        int tmp = x % y;
        x = y;
        y = tmp;
    }
    return z % y == 0;

}