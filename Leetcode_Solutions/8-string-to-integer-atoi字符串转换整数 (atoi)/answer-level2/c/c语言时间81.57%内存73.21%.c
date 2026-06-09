int myAtoi(char * str){
    int numlen = strlen(str);
    int i = 0;
    
    while (str[i] == ' ') {
        i++;
    }
    
    int flag = 1;
    double res = 0;
    int bit = 0;
    
    if (str[i] == '-') {
        i++;
        flag = -1;
    } else if (str[i] == '+') {
        i++;
        flag = 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        bit = (int)(str[i] - '0');        
        res = res * 10 + bit;
      
            if (res > INT_MAX) {
                if (flag == 1) 
                 return INT_MAX;
                if(flag == -1) 
                   return INT_MIN;
            }   
        i++;
    }
    
    res = (int)res;
    if (flag == -1) {
        return -res;
    } else {
        return res;
    }  
}
