我的题解的成绩为：
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.5 MB, 在所有 C 提交中击败了100.00%的用户
下面贴出我的代码：
int getVal( char ch )
{
    switch( ch)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;      
        default : return 0;  
    }
}

int romanToInt(char * s){
    char *p = s, lastCh = '\0';
    int ret = 0;

    while( *p )
    {
        if( ((lastCh == 'I') && ((*p == 'V') || (*p == 'X'))) || 
            ((lastCh == 'X') && ((*p == 'L') || (*p == 'C'))) || 
            ((lastCh == 'C') && ((*p == 'D') || (*p == 'M'))) )
        {
            ret -= getVal(lastCh)<<1;
        }
        ret += getVal(*p);
        lastCh = *p;
        p++;
    }
    return ret;
}