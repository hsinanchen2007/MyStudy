int myAtoi(char * str){
    char *begin = str;
    char *end;
    int flag = 1;
    long int sum = 0;
    int maxInt = 1024 * 1024 * 1024 * 2 - 1;
    int minInt = -1024 * 1024 * 1024 * 2;
    if (str == NULL) return 0;
    while (*begin == ' ') {
        begin++;  
    }
    if (!(*begin - '0' >= 0 && *begin - '0' <= 9) && *begin != '+' && *begin != '-') return 0;
    while (*begin != '+' && *begin != '-' && 
           !(*begin - '0' >= 0 && *begin - '0' <= 9) && *begin != '\0') {
        begin++;  
    }
    
    if (*begin == '+') {
        flag = 1;
        begin++;
        
    } else if (*begin == '-') {
        flag = -1;
        begin++;
        
    }
    end = begin;
    while(*end - '0' >= 0 && *end - '0' <= 9 && *end != '\0') {
        end++;
    }
    *end = '\0';
    while (end > begin) {
        sum = sum * 10 + (*begin - '0');
        if (flag == 1 && sum >= maxInt) return maxInt;
        if (flag == -1 && (sum * -1) <= minInt) return minInt;
        begin++;
    }
    return flag == 1 ? sum : -sum;
}