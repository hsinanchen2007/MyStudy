bool checkPerfectNumber(int num)
{
    int i;
    int sum = 0;
    for(i = 1; i <= sqrt(num); i ++)
    {
        if(num % i == 0)
        {
            sum = sum + i + (num / i);
        }
    }
    if (sum - num == num && num != 1 && num != 0)
        return true;
    else return false;
}

