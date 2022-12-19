int reverse(int x){
    long long int y=0,k;
    while(x){
        y*=10;
        y+=x%10;
        k=(y>>31);
        if(k!=0&&k!=-1)return 0;
        x/=10;
    }
    return y;
}