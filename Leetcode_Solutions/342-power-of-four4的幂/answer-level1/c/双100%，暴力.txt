```
bool isPowerOfFour(int num){
    if(num == 1)
        return true;
    if(num % 4 != 0)
        return false;
    int i;
    for(i = 4;i <= num;i *= 4)
    {
        if(i == num)
        {
            return true;
        }
        if(num - i < num / 4)
        {
            return false;
        }
    }
    return false;
}
```
