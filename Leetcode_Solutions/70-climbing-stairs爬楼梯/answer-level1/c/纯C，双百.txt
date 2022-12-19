int climbStairs(int n){
    int i, val_1 = 1, val_2 = 2, ret;

    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else
    {
        for(i = 3; i <= n; i++)
        {
            ret = val_1 + val_2;
            val_1 = val_2;
            val_2 = ret;
        }

        return ret;
    }
}