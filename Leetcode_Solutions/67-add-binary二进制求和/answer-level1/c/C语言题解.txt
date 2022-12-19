
#define MAX_LEN 1000;

char * reverse(char* s, int max_len){
    int s_len = strlen(s);
    char* rev_s = (char*)malloc((max_len+1)*sizeof(char));
    memset(rev_s, '0', max_len);
    
    for(int i = 0; i < s_len/2; i++)
    {
        char tmp = s[i];
        s[i] = s[s_len-i-1];
        s[s_len-i-1] = tmp;
    }
    
    for(int i = 0; i < s_len; i++)
    {
         rev_s[i] = s[i];
    }
    rev_s[max_len] = '\0';
    return rev_s;
}

char * addBinary(char * a, char * b){
    int a_len = strlen(a);
    int b_len = strlen(b);
    int max_len = (a_len > b_len)? a_len:b_len;
    char *sum = (char*)malloc((max_len+2)*sizeof(char));
    memset(sum, '0', max_len+1);

    char *rev_a = reverse(a, max_len);
    char *rev_b = reverse(b, max_len);
    int pre = 0;
    int sum_len = max_len;
    
    for(int i = 0; i < max_len; i++)
    {
        int a_int = rev_a[i] - '0';
        int b_int = rev_b[i] - '0';
        
        if (a_int + b_int + pre == 0) {
            pre = 0;
            sum[i] = '0';
        }
        else if (a_int + b_int + pre == 1) {
            pre = 0;
            sum[i] = '1';
        }
        else if (a_int + b_int + pre == 2) {
            pre = 1;
            sum[i] = '0';
        }
        else if (a_int + b_int + pre == 3) {
            pre = 1;
            sum[i] = '1';
        }        
    }
    
    if (pre == 1) {
        sum[max_len] = '1';
        sum[max_len+1] = '\0';
        sum_len = max_len+1;
    }
    else
        sum[max_len] = '\0';
    return reverse(sum, sum_len);
}