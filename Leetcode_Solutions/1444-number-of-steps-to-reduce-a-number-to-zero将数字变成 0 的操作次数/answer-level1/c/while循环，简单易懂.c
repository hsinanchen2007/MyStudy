int numberOfSteps (int num){
    int times;
    times = 0;
    while(num)
    {
        if(num % 2 == 1)
        {
            num = num-1;
            times++;
            if(num == 0)
            break;
        }
        num = num/2;
        times++;
    }
    return times;
}