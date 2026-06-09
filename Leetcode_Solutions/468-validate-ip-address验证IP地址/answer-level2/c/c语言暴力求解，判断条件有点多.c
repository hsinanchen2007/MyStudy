```
#define IPV4_MIN 0
#define IPV4_MAX 255
#define IPV4_COUNT 3
#define IPV6_COUNT 7
#define IPV6_NUM 4

bool IsIpv4Addr(char *addr)
{   
    int i;
    int temp;
    int count = 0;

    if (*addr == '0' || *addr == '.') { // 第一个字符是‘0’或者‘.’
        return false;
    }

    temp = atoi(addr);
    if (temp > IPV4_MAX || temp < IPV4_MIN) { // 第一个数字超过了IPV4地址的取值范围
        return false;
    }

    while (*addr != '\0') {
        if (*addr == '.') {
            addr++;
            if (*addr == '.' || *addr == '-' || *addr == '\0') { // 连续出现‘.’、‘.’后出现‘-’、以‘.’结束
                return false;
            }
            if (*addr == '0' && *(addr + 1) != '.' && *(addr + 1) != '\0') { // 以0开头，非法
                return false;
            }
            temp = atoi(addr);
            if (temp > IPV4_MAX || temp < IPV4_MIN) { // 超过了IPV4地址的取值范围
                return false;
            }

            count++;
        } else {
            if (!(*addr >= '0' && *addr <= '9')) { // 每个字符的取值范围
                return false;
            }
        }

        addr++;
    }

    if (count != IPV4_COUNT) { // ‘.’数量不等于4
        return false;
    }

    return true;
}

bool IsIpv6Addr(char *addr)
{
    int i;
    int count = 0;
    int num = 0;

    if (*addr == ':') { // 第一个字符是‘:’
        return false;
    }

    while (*addr != '\0') {
        if (*addr == ':') {
            addr++;
            count++;
            num = 0;

            if (*addr == ':') { //连续出现‘:’
                return false;
            }
        }

        if ((*addr >= '0' && *addr <= '9') ||
            (*addr >= 'A' && *addr <= 'F') ||
            (*addr >= 'a' && *addr <= 'f')) {
            num++;
            if (num > IPV6_NUM) { // 数量超4个
                return false;
            }
        } else {
            return false;
        }

        addr++;
    }

    if (count != IPV6_COUNT) { // ‘:’数量非7个
        return false;
    }

    return true;
}

char * validIPAddress(char * IP){
    char *addr = IP;

    while (*IP != '\0') {
        if (*IP == '.') {
            if (IsIpv4Addr(addr)) {
                return ("IPv4");
            }
            break;
        }

        if (*IP == ':') {
            if (IsIpv6Addr(addr)) {
                return ("IPv6");
            }
            break;
        }

        IP++;
    }

    return ("Neither");
}
```
