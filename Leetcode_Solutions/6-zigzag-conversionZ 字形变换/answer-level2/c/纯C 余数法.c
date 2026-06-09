纯C 余数法
```
char * convert(char * s, int numRows){
    if(1 >= numRows)
    {
        return s;
    }

    int uStrLen = strlen(s);
    char* cConvertStr = (char*)malloc(sizeof(char) * (uStrLen + 1));

    int uIndexOfRow = 0;
    int uIndexOfStr = 0;
    int uIndexOfCvtStr = 0;

    int uStepLen = 2 + (numRows - 2) * 2; // arithmetic progression
    int uRemainder = 0;

    for(uIndexOfRow = 0; uIndexOfRow <= (numRows - 1); uIndexOfRow++) // create new string by line of Z
    {
        for(uIndexOfStr = 0; uIndexOfStr <= (uStrLen - 1); uIndexOfStr++) // find the char belong to its line
        {
            uRemainder = uIndexOfStr % uStepLen;

            // the char on straight part or, diagonal part
            if((uRemainder == uIndexOfRow) || (uRemainder + uIndexOfRow == uStepLen))
            {
                cConvertStr[uIndexOfCvtStr++] = s[uIndexOfStr];
            }
        }
    }

    cConvertStr[uIndexOfCvtStr] = '\0';

    return cConvertStr;
}
```

