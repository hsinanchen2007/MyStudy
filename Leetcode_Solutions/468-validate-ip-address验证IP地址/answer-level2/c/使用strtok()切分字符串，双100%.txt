这是对C充满恶意的一道题~
```
#define NEITHER    "Neither"
#define IPV4       "IPv4"
#define IPV6       "IPv6"

typedef enum {
    M_IPV4,
    M_IPV6,
    M_NEITHER
} MTYPE;

int CheckIpNode(char * IP, int ipLen) {
    int sum1 = 0;
    int sum2 = 0;
    int num= 0;
    for(int i = 0; i < ipLen; i++) {
        if(isdigit(IP[i])) {
            continue;
        }
        if(IP[i] =='.' ) {
            sum1 ++;
        }
        else if(IP[i] ==':' ) {
            sum2 ++;
        }
        else if(isalpha(IP[i])) {
            if((IP[i] <= 'F' && IP[i] >= 'A') || (IP[i] <= 'f' && IP[i] >= 'a')) {
                num ++;
            }
            else {
                return M_NEITHER;
            }
            
        }
        else {
            return M_NEITHER;
        }
    }

    if(sum1 == 3 && sum2 == 0 && num == 0) {
        return M_IPV4;
    }
    if(sum1 == 0 && sum2 == 7) {
        return M_IPV6;
    }
    return M_NEITHER;
}

char * validIPAddress(char * IP){
    int ipLen = strlen(IP);
    MTYPE type = CheckIpNode(IP, ipLen);   
    int num = 0;
    if(type == M_IPV4) {
        char* p = strtok(IP, ".");
        while(p != NULL) { 
            if(p[0] == '0' && strlen(p) > 1) {
                break;
            }
            int value = 0;
            sscanf(p, "%d", &value);
            
            if(value < 0 || value >= 256) {
                break;
            }
            num ++;
            p = strtok(NULL, ".");
        }
        if(num == 4) 
            return IPV4;
    }
    else if(type == M_IPV6) {
        char* p = strtok(IP, ":");
        while(p != NULL) {
            int len = strlen(p);
            if(len > 4) {
                break;
            }
            int value = 0;
            sscanf(p, "%x", &value);
            num ++;
            p = strtok(NULL, ":");
        }
        if(num == 8) 
            return IPV6;
    }
    
    return NEITHER;
}
```
