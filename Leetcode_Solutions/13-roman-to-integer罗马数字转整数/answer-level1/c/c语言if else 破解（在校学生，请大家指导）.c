int romanToInt(char * s){
    int count = 0;
	char *p = s;
	while(*s != '\0'){
        if(*p == 'I'){
                p++;
                if(*p == 'V'){
                    count +=4;
                    s = p;
                    
                }else if(*p == 'X'){
                    count +=9;
                    s = p;
                    
                }else{
                    count += 1;
                    p = s;
                }
            }
        else if(*p == 'X'){
                p++;
                if(*p == 'L'){
                    count +=40;
                    s = p;
                    
                }else if(*p == 'C'){
                    count +=90;
                    s = p;
                    
                }else{
                    count += 10;
                    p = s;
                }
            }
        else if(*p == 'C'){
                p++;
                if(*p == 'D'){
                    count +=400;
                    s = p;
                    
                }else if(*p == 'M'){
                    count +=900;
                    s = p;
                    
                }else{
                    count += 100;
                    p = s;
                }
            }
        else if(*p == 'V'){
            count += 5;
        }
         else if(*p == 'L'){
            count += 50;
        }
         else if(*p == 'D'){
            count += 500;
        }
         else if(*p == 'M'){
            count += 1000;
        }
        p++;
        s = p;
    }
    return count;
}