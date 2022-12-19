单纯的if语句写成的
int kthGrammar(int N, int K){
    if(N==1)
    {
        return 0;
    }
    int k=K;
    if(k%2!=0)    //判断K是偶数位还是奇数位
    {
        if(kthGrammar(N-1,(k+1)/2)==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(kthGrammar(N-1,(k+1)/2)==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}