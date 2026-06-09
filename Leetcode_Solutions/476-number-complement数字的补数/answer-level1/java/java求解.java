        int base=1;
        int sum=0;
        while(num!=0){
            sum+=base*((num%2)^1);
            num/=2;
            base*=2;
        }
       return sum;
        要什么就求什么就好了,没必要绕一下.