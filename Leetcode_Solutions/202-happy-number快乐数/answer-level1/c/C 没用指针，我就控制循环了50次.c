```
bool isHappy(int n){
    int count = 0, sum = 0, i;
    while(1)
    {
       
        i = n % 10;
        sum += i * i;
        n /= 10;
        count++;
        
        if(sum == 1 && n == 0)
        {
            return true;
        }
        if(n == 0)
        {
            n = sum;
            sum = 0;
        }
        if(count >= 50)
        {
            return false;
        }
    }
    return false;
}

```
