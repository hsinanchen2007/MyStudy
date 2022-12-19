
int hammingDistance(int x, int y){
    int temp = x ^ y;
    int result = 0;
    while(temp > 0) {
        result += temp % 2 > 0 ? 1 : 0;
        temp /= 2;
    }
    return result;
}
