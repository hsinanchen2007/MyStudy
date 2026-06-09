```c
bool isOneBitCharacter(int* bits, int bitsSize)
{
    int i,j;
    for(i=0;i<bitsSize;i++)
    {
        if(bits[i]==0)
        {
            j=0;
        }
        if(bits[i]==1)
        {
            i++;
            j=1;
        }
    }
    if(j==1)
        return false;
    else
        return true;
}
