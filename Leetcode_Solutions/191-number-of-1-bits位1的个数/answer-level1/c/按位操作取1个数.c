int hammingWeight(uint32_t n) 
{
    int num = 0;
    for(int i ;i<32;i++)
    {
        if(n & 1 == 1)
            num++;

        n = n >> 1;
    }
    return num;
}