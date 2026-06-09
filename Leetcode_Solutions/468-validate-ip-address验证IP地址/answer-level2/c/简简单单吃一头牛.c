```
bool checkAf(char c)
{
    if (c >= 'a' && c <= 'f') {
        return true;
    }
    if (c >= 'A' && c <= 'F') {
        return true;
    }    
    return false;
}
bool check09(char c)
{
    if (c >= '0' && c <= '9') {
        return true;
    }  
    return false;
}

char* validIPAddress(char* IP)
{
    int len = strlen(IP);
    char IPvX[10][10] = {0};
    int tag1 = 0, tag2 = 0, coutIPv4 = 0, coutIPv6 = 0, countNums = 0;
    int result = 0;

    if (!IP || len < 7 || len > 39) {
        return "Neither";
    }

    for (int i = 0; i < len; i++) {
        if ((IP[i] >= '0' &&  IP[i] <= '9') ||  
            (IP[i] >= 'a' &&  IP[i] <= 'f') ||
            (IP[i] >= 'A' &&  IP[i] <= 'F')){
            IPvX[tag1][tag2++] = IP[i];
            // printf("%s %s %s %s %d\n", IPvX[0], IPvX[1], IPvX[2], IPvX[3], atoi(IPvX[0]));
        } else if (IP[i] == '.') {
            tag1++;
            if (tag1 > 3) {
                return "Neither";
            }          
            if (tag2 == 0) {
                return "Neither";
            }
            tag2 = 0;
            coutIPv4++;
            if (result == 6) {
                return "Neither";
            }
            result = 4; // "IPv4";
        } else if (IP[i] == ':') {
            tag1++;
            if (tag1 > 7) {
                return "Neither";
            }            
            if (tag2 == 0) {
                return "Neither";
            }            
            tag2 = 0;
            coutIPv6++;
            if (result == 4) {
                return "Neither";
            }
            result = 6; // "IPv6";
        }
    }
    for (int i = 0; i < len; i++) {
        if (result == 4 && (!check09(IP[i])) && IP[i] != '.') {
            return "Neither";
        }
        if (result == 6 && (!check09(IP[i])) && IP[i] != ':' && (!checkAf(IP[i]))) {
            return "Neither";
        }        
    }
    if (result == 4) {
       if (coutIPv4 != 3 || atoi(IPvX[0]) > 255 || atoi(IPvX[1]) > 255 || atoi(IPvX[2]) > 255 || atoi(IPvX[3]) > 255) {
           return "Neither";
       }
       if ((IPvX[0][0] == '0' && strlen(IPvX[0]) > 1) || 
            (IPvX[1][0] == '0' && strlen(IPvX[1]) > 1) || 
            (IPvX[2][0] == '0' && strlen(IPvX[2]) > 1) || 
            (IPvX[3][0] == '0' && strlen(IPvX[3]) > 1)) {
           return "Neither";
       }
       if (tag1 != 3 || tag2 == 0) {
           return "Neither";
       }
       return "IPv4";
    }
    if (result == 6) {
        if (coutIPv6 != 7) {
           return "Neither";
        }
       if ((strlen(IPvX[0]) > 4) || 
            (strlen(IPvX[1]) > 4) || 
            (strlen(IPvX[2]) > 4) ||
            (strlen(IPvX[3]) > 4) ||
            (strlen(IPvX[4]) > 4) ||
            (strlen(IPvX[5]) > 4) ||
            (strlen(IPvX[6]) > 4) ||
            (strlen(IPvX[7]) > 4)) {
           return "Neither";
       }
       if (tag1 != 7 || tag2 == 0) {
           return "Neither";
       }       
        return "IPv6";
    }
    
    return "Neither";

}
```
