int maxNumberOfBalloons(char * text)
{

    int i = 0, num = 0;
    int b_cnt=0, a_cnt=0, l_cnt=0, o_cnt=0, n_cnt=0;
    
    while( '\0' != text[i] )
    {
        if( 'b' == text[i] )
            b_cnt ++;
        else if( 'a' == text[i] )
            a_cnt ++;
        else if( 'l' == text[i] )
            l_cnt ++;
        else if( 'o' == text[i] )
            o_cnt ++;
        else if( 'n' == text[i] )
            n_cnt ++;
        
        i++;
    }
       
    num = (b_cnt < a_cnt) ? b_cnt : a_cnt;
    num = (num < (l_cnt /= 2)) ? num : l_cnt;
    num = (num < (o_cnt /= 2)) ? num : o_cnt;   
    num = (num < n_cnt) ? num : n_cnt;
    
    return num;
}
