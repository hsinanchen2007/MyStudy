
int chartoint(char c)
{
    switch(c) {
    case 'I' : return 1; break;
    case 'X' : return 10; break;
    case 'V' : return 5; break;
    case 'L' : return 50; break;
    case 'C' : return 100; break;
    case 'D' : return 500; break;
    case 'M' : return 1000; break;
    default : break;
    }
    return 0;
}
int romanToInt(char * s) {

    int i, j, value = 0;
    for (i = 0; i < strlen(s); i++) {
        j = i + 1;
        if (chartoint(s[i]) < chartoint(s[j]) ) { //数字小的在左边时
            value += ( chartoint(s[j]) - chartoint(s[i]) );
            i++;
        } else {
            value += chartoint(s[i]); 
        }

    }
    return value;

}