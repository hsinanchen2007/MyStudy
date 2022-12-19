int hammingDistance(int x, int y){
    int sum = x^y;
    int count = 0;
    while(sum >0)
    {
        if(sum&1==1) {
            count++;
        }
        sum = sum>>1;
    }
    return count;
}