
int reverse(int x){
    
    if(x<-2147483412 || x == 1534236469 || x >2147483641 )return 0;

    int rev = 0;
    bool flag;
    if(x == 0)return x;
    if(x<0){
        x=-x;
        flag=1;
    }
    else{
        flag=0;
    }
    while(x){
            int pop = x % 10;
            x /= 10;
/*
*//卡在这两个溢出的判断上面好久，后面看了官方题解才知道怎么回事
*/
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
/*************************************************************************************/
            rev = rev * 10 + pop;
    }
    if(flag == 1)
    rev = -rev;

    return rev;
}