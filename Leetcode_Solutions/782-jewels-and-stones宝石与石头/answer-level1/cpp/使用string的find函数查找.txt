int numJewelsInStones(string J, string S) {
    int diomandNum = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (J.find(S[i], 0) != J.npos)
        {
            diomandNum++;
        }
    }

    return diomandNum;
  
}