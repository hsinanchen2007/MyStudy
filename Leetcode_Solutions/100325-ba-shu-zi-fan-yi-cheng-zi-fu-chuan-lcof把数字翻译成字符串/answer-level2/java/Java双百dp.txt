public int translateNum(int num) {
        if(num < 0)return 0;
        if(num <= 9)return 1;
        if(num <= 25)return 2;
        int n1 = num%10;
        int n2;
        num/=10;
        int count1 = 1;
        int count2 = 1;
        while(num>0){
            n2 = num%10;
            int c = 0;
            if(n2!=0 && n2*10+n1<=25){
                c = count1 + count2;
            }else{
                c = count2;
            }
            count1 = count2;
            count2 = c;
            n1 = n2;
            num/=10;
        }
        return count2;
    }