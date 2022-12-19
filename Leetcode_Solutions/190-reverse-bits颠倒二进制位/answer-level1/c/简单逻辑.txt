小白，勿喷
uint32_t reverseBits(uint32_t n) {
    uint32_t xxx=0,ccc=0;
    if(n&0x80000000)
    {
        while(n != 0)
        {  
            xxx =n%2;
            n = n/2;
            ccc = ccc*2+xxx;
        

        }
    }
    else
    {
        n = ~n;
        while(n!=0)
        {
            xxx =n%2;
            n = n/2;
            ccc = ccc*2+xxx;
        }
        ccc = ~ccc;
    }

    return ccc;
}
采用最简单暴力的解法，其实除2乘2和位运算的意思是一样的，也可以采用查表法来优化时间，但空间消耗过大