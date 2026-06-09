bool canMeasureWater(int x, int y, int z){
    int rem =0, max_rem = 1,x_s=0,y_s=0;

    x_s=x;
    y_s=y;
   if(y==0&&x==0)
    {
        if(z==0)
        return true;
        else
        return false;
    }

    else if(x==0)
    {
        if(z==y||z==0)
        return true;
        else
        return false;
    }

   else if(y==0)
    {
        if(z==x||z==0)
        return true;
        else
        return false;
    }


    while(max_rem!=0)
    {
        if(x>y){
            max_rem=x%y;
            x=max_rem;
            rem = y;
        }
        else{
            max_rem=y%x;
            y=max_rem;
            rem = x;
        }

    }

    if(z%rem==0 && z<=x_s+y_s)
    return true;
    else
    return false;

}