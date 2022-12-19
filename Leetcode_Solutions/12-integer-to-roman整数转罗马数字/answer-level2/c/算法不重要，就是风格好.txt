char hundredsRomanChar[3] = {'C', 'D', 'M'};
char tenRomanChar[3] = {'X', 'L', 'C'};
char bitRomanChar[3] = {'I', 'V', 'X'};

#define ROMAN_MAX_SIZE 64

#define HUNDRED 100
#define TEN 10
#define ONE 1

char getCharForBitType(int bitType, int index)
{
    char RomanChar;
    switch (bitType){
        case HUNDRED:
            RomanChar = hundredsRomanChar[index];
            break;
        case TEN:
            RomanChar = tenRomanChar[index];
            break;
        case ONE:
            RomanChar = bitRomanChar[index];
            break;
        default:
            RomanChar = '\0';
            break;            
    }
    return RomanChar;    
}

void bitnum2char(int num, int bitType, char *s, int *pIndex)
{
    int i;    
    switch (num)
    {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            for(i=0; i<num; ++i) {
                s[*pIndex] = getCharForBitType(bitType, 0);                
                (*pIndex) = (*pIndex) + 1;
            }
            break;
        case 4:
            s[*pIndex] = getCharForBitType(bitType, 0);
            (*pIndex) = (*pIndex) + 1;
            s[*pIndex] = getCharForBitType(bitType, 1);
            (*pIndex) = (*pIndex) + 1;
            break;
        case 5:
            s[*pIndex] = getCharForBitType(bitType, 1);            
            (*pIndex) = (*pIndex) + 1;           
            break;
        case 6:
        case 7:
        case 8:
            s[*pIndex] = getCharForBitType(bitType, 1);
            (*pIndex) = (*pIndex) + 1;
            for(i = 5; i < num; ++i) {
               s[*pIndex] = getCharForBitType(bitType, 0);
               (*pIndex) = (*pIndex) + 1;
            }
            break;
        case 9:
            s[*pIndex] = getCharForBitType(bitType, 0);
            (*pIndex) = (*pIndex) + 1;
            s[*pIndex] = getCharForBitType(bitType, 2);
            (*pIndex) = (*pIndex) + 1;
            break;
    }   
    return;
}

char * intToRoman(int num){
    int thousands_bit, hundreds_bit, ten_bit, one_bit, i;
    int index = 0;
    thousands_bit = num/1000;
    hundreds_bit = (num%1000)/100;
    ten_bit = (num%100)/10;
    one_bit = num%10;
    
    
    char *p = NULL;
    p = (char *)malloc(ROMAN_MAX_SIZE);
    (void) memset(p, 0, ROMAN_MAX_SIZE);
    for(i = 0; i < thousands_bit; ++i)
    {
        p[index] = 'M';
        index++;
    }   

    bitnum2char(hundreds_bit, HUNDRED, p, &index);
    bitnum2char(ten_bit, TEN, p, &index);
    bitnum2char(one_bit, ONE, p, &index); 
    
    return p;

}