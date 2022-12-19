/*公约数*/
int divisorCal(int a, int b)
{
    return b == 0 ? a : divisorCal(b, a % b);
}

bool hasGroupsSizeX(int* deck, int deckSize){

    if(deckSize<2)
    {
        return false;
    }

    int hash[10000] = {0};
    int i = 0;
    int divisor = 0;

    for(i=0;i<deckSize;i++)
    {
        hash[deck[i]]++;
    }

    for(i=0; i<10000;i++)
    {
        if(hash[i] != 0)
        {
            divisor = divisorCal(hash[i],divisor);
            if(divisor<2)
            {
                return false;
            }
            
        }
    }

    return true ; 
}