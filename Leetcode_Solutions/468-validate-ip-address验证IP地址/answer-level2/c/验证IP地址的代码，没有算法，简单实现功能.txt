题目的本身不是很复杂，主要是练习编码，里面是我自己的实现，供大家参考

```
#define FUN_FILE_DESC(x)   1 

#if FUN_FILE_DESC("public")
#define MAX_POS_IPV4_FLAG 3
#define MAX_POS_IPV6_FLAG 7

#define IPV4_NUM_LEN      3
#define IPV6_NUM_LEN      4

#define IPV4_STR      "IPv4"
#define IPV6_STR      "IPv6"
#define NOIP_STR      "Neither"

bool isNumber(char input) {
    if ((input >= '0') && (input <= '9')) {
        return true;
    }

    return false;
}

bool isHexNumber(char input) {
    if ((input >= '0') && (input <= '9')) {
        return true;
    }

    if ((input >= 'a') && (input <= 'f')) {
        return true;
    }

    if ((input >= 'A') && (input <= 'F')) {
        return true;
    }    
    return false;
}
#endif

#if FUN_FILE_DESC("IPV4")
bool isIpV4(char *IP) {
    int index;

    for (index = 0; index <= MAX_POS_IPV4_FLAG; index++) {
        if (IP[index] == '\0') {
            break;
        }

        if (IP[index] == '.') {
            return true;
        }
    }

    return false;
}

bool checkIpV4Val(char *num, int Len) {
    int numLen = Len;
    int ipVal;

    if ((numLen > IPV4_NUM_LEN) || (numLen < 1)) {
        return false;
    }

    if ((numLen > 1) && (num[0] == '0')) {
        return false;
    }

    ipVal = atol(num);
    if (ipVal >= 256) {
        return false;
    }

    return true;
}

bool isValidIpV4(char *IP) {
    int index;
    int numLen = 0;
    int flagCount = 0;
    char num[IPV4_NUM_LEN + 1] = {0};

    for (index = 0; ; index++) {
        if (IP[index] == '\0') {
            break;
        }

        if (IP[index] != '.') {
            if (!isNumber(IP[index])) {
                return false;
            }

            if (numLen > IPV4_NUM_LEN) {
                return false;
            }

            num[numLen++] = IP[index];
            continue;
        }
        flagCount++;
        if (flagCount > MAX_POS_IPV4_FLAG) {
            return false;
        }

        if (!checkIpV4Val(num, numLen)) {
            return false;
        }
        numLen = 0;
        memset(num, 0x0, sizeof(num));        
    }

    if (flagCount != MAX_POS_IPV4_FLAG) {
        return false;
    }

    if (!checkIpV4Val(num, numLen)) {
        return false;
    }
    return true;
}
#endif

#if FUN_FILE_DESC("IPV6")
    /*
IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。

同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。   
    */
bool checkIpV6Val(char *num, int Len) {
    int numLen = Len;
    int ipVal;

    if ((numLen > IPV6_NUM_LEN) || (numLen < 1)) {
        return false;
    }

    /*
    if ((numLen > 1) && (num[0] == '0') && (num[1] == '0')) {
        return false;
    }
    */
    return true;
}

bool isValidIpV6(char * IP) {
    int index;
    int numLen = 0;
    int flagCount = 0;
    char num[IPV6_NUM_LEN + 1] = {0};

    for (index = 0; IP[index] != '\0'; index++) {
        if (IP[index] != ':') {
            if (!isHexNumber(IP[index])) {
                return false;
            }

            if (numLen > IPV6_NUM_LEN) {
                return false;
            }

            num[numLen++] = IP[index];
            continue;
        }
        flagCount++;
        if (flagCount > MAX_POS_IPV6_FLAG) {
            return false;
        }

        if (!checkIpV6Val(num, numLen)) {
            return false;
        }
        memset(num, 0x0, sizeof(num));
        numLen = 0;
    }

    if (flagCount != MAX_POS_IPV6_FLAG) {
        return false;
    }

    if (!checkIpV6Val(num, numLen)) {
        return false;
    }
    return true;
}
#endif

char * validIPAddress(char * IP){
    bool isIPV4;
    bool isIPV6;

    isIPV4 = isIpV4(IP);
    if (isIPV4) {
        isIPV4 = isValidIpV4(IP);
        if(isIPV4){
            return IPV4_STR;
        }
    }
    else {
        isIPV6 = isValidIpV6(IP);
        if (isIPV6) {
            return IPV6_STR;
        }
    }
    return NOIP_STR;
}
```
