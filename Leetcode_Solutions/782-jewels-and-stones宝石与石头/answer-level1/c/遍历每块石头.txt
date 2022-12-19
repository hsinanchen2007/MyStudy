int numJewelsInStones(char * J, char * S)
{
    int i = 0, j = 0, reNum = 0;
    for(i = 0; i < strlen(J); i++)
    {
        for(j = 0; j < strlen(S); j++)
        {
            if(J[i] == S[j])
            {
                reNum++;
            }
        }
    }
    return reNum;
}