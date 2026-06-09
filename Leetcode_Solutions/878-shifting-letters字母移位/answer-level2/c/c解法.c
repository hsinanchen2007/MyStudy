
char * shiftingLetters(char * S, int* shifts, int shiftsSize){
    int i;
    int temp = 0;
    int overBuf;
    for(i=shiftsSize-1; i>=0; i--)
    {
        temp += shifts[i];  //计算倒数第i个字母需要位移的次数
        temp = temp%26;      //对位移次数x进行化简
        overBuf = S[i] + temp;
        if(overBuf > 'z')   //判断结果是否过界
        {
            S[i] = 'a' + (overBuf-'z'-1);
        } 
        else S[i] = overBuf;            
    }
    return S;
}

