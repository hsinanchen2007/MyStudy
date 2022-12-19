int addDigits(int num){
       if(num<10){
           return num;
       }
    int sum=0;
    while(num){
        int d=num%10;
        sum=sum+d;
        num=num/10;
    }
    return addDigits(sum);
}