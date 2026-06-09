思路将输入依次除2取余，记录位数j，当余数为0时，sum等于sum加上pow(2,j),直到除完为止。

```

int bitwiseComplement(int N){
    if(N == 0)
        return 1;
    int temp = N;
    int j = 0;
    int sum = 0;
    int record;
    while(temp != 0)
    {
        record = temp % 2;
        if(record == 0)
        {   
            sum = sum + pow(2,j);
        }
        j++;
        temp = temp/2;       
    }
    return sum;
}
```
