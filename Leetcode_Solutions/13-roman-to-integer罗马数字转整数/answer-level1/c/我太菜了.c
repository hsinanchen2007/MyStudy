#define nI 1
#define nV 5
#define nX 10
#define nL 50
#define nC 100
#define nD 500
#define nM 1000

int romanToInt(char * s){
    int num=0;
    for(int i=0;*(s+i);i++)
    {
        switch(*(s+i))
        {
            case 'I':num+=*(s+i+1)=='V'||*(s+i+1)=='X'?-nI:nI;break;
            case 'V':num+=nV;break;
            case 'X':num+=*(s+i+1)=='L'||*(s+i+1)=='C'?-nX:nX;break;
            case 'L':num+=nL;break;
            case 'C':num+=*(s+i+1)=='D'||*(s+i+1)=='M'?-nC:nC;break;
            case 'D':num+=nD;break;
            case 'M':num+=nM;break;
            default:printf("error 1");
        }
    }
    return num;
}