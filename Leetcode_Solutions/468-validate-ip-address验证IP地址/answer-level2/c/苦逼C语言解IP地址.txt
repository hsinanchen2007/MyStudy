# 苦逼C语言解IP地址

这道题并不难，但是比较烦。为了解这道题，我们要做这么几件事：
1. 判断字符串以什么为分隔符，有了分隔符就知道我们要求解的是IPV4还是IPV6了
2. 对字符串分隔符前的数字进行判断

## IPV4数字判断
1. IPV4不允许多个数字时，以0开头
2. IPV4不允许数字超过255
3. IPV4必须有四个数字

## IPV6数字判断
1. IPV6要求要么是数字，要么是a-f\A-F
2. IPV6不允许超过4个字符

过了这几个个判断，数字校验就过了。
不过不知道我的内存咋使用这么多，我都没有申请额外数组，而且这个运行时间也很奇怪，LeetCode服务器出问题了吧
![截图.PNG](https://pic.leetcode-cn.com/8d32fab83200c8e76a595a87402c0678d23681a6203a49a1addb2683353b3898-%E6%88%AA%E5%9B%BE.PNG)
```c
#define IPV4_FLAG 1
#define IPV6_FLAG 2

char *bad = "Neither";
char *IPv4 = "IPv4";
char *IPv6 = "IPv6";
char IPv4Split = '.';
char IPv6Split = ':';

bool isValidIPV4Num(char *ip, int begin, int end) {
    int num = 0;
    int order = 0;
    if (ip[begin] == '0' && begin != end) {
        return false;
    }

    if (end - begin > 2)
        return false;

    for (int i = begin; i <= end; ++i, ++order) {
        if (ip[i] < '0' || ip[i] > '9') {
            return false;
        }

        num = num * 10 + (ip[i] - '0');
    }

    if (num > 255)
        return false;

    return true;
}

bool isValidIPV6Num(char *IP, int begin, int end) {
    if (end - begin > 3) {
        return false;
    }

    for (int i = begin; i <= end ; ++i) {
        if (IP[i] >= '0' && IP[i] <= '9') {
            continue;
        }

        if (IP[i] >= 'a' && IP[i] <= 'f') {
            continue;
        }

        if (IP[i] >= 'A' && IP[i] <= 'F') {
            continue;
        }

        return false;
    }

    return true;
}

bool isValidIPNum(char *IP, int begin, int end, char split) {
    if (split == IPv6Split) {
        return isValidIPV6Num(IP, begin, end);
    }
    return isValidIPV4Num(IP, begin, end);
}

char *doCheck(char *IP, char split, int needCount) {
    int beginIndex = 0;
    int endIndex = 0;
    int times = 0;
    int len = 0;

    for (; IP[len] != '\0'; ++len) {
        if (IP[len] != split) {
            continue;
        }

        ++times;
        endIndex = len - 1;
        if (IP[len + 1] == '\0' || IP[len] == IP[len + 1]) {
            return bad;
        }

        if (!isValidIPNum(IP, beginIndex, endIndex, split)) {
            return bad;
        }

        beginIndex = len + 1;
    }

    if (beginIndex < len) {
        ++times;
        if (!isValidIPNum(IP, beginIndex, len - 1, split)) {
            return bad;
        }
    }

    if (times != needCount) {
        return bad;
    }

    if (split == IPv4Split) {

        return IPv4;
    }

    return IPv6;
}

char *validIPAddress(char *IP) {
    int flag = 0;
    for (int i = 0; IP[i] != '\0'; ++i) {
        if (IP[i] == IPv4Split) {
            flag = IPV4_FLAG;
            break;
        }

        if (IP[i] == IPv6Split) {
            flag = IPV6_FLAG;
            break;
        }
    }

    if (flag == IPV4_FLAG) {
        return doCheck(IP, IPv4Split, 4);
    } else if (flag == IPV6_FLAG) {
        return doCheck(IP, IPv6Split, 8);
    }

    return bad;
}
```