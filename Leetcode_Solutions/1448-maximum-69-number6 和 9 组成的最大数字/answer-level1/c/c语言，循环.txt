循环获取每个位数上的值，遇到第一个6则转化为9


int maximum69Number (int num){
    int s=num,n=0;
    //获取该整数的位数
    while(num>=1){
        num/=10;
        n++;
    }

    int sum=0;
    //设置一个bool类型，为0，当遇到第一个6时转化为9，并令bool=1
    bool b=0;
    while(s>=1){
        int x=s/pow(10,n-1);
        if(x==6&&b==0) {
            x=9;
            b=1;
        }
        sum=sum*10+x;
        s=s%(int)pow(10,n-1);
        n--;
    }
    return sum;
}