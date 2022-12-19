#define POS 1
#define NAG 0
#define TEN 10
#define CHG_CHAR_TO_NUM(c) ((c) + 0 - '0')

bool myIsCharNum(char c)
{
    return (c >= '0' && c <= '9');
}

bool MyCheckValid(char * str, int * offset) 
{
    char *p = str;
    int plus = 0;

    while(*p == ' ') {
        p++;
        plus++;
    }
    if (myIsCharNum(*p)) {
        *offset = plus;
        return true;
    } else if (*p == '-' || *p == '+') {
        if (myIsCharNum(*++p)) {
            *offset = plus;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int MySearchOffsetEnd(char * p)
{
    int offset = 0;
    while (myIsCharNum(*p)) {
        p++;
        offset++;
    }
    offset--;
    return offset;
}

bool MyOutBandCheck(unsigned int rev, int num, int flag)
{
    if (flag == POS) {
        if (rev > (INT_MAX - num) / TEN) {
            return false;
        } else {
            return true;
        }
    } else {
        if (rev > ((unsigned int)INT_MIN - num) / TEN) {
            return false;
        } else {
            return true;
        }
    }
}

int myAtoi(char * str)
{
    int offset;
    int offEnd;
    int flag;
    int i;
    unsigned int rev = 0;

    if (!MyCheckValid(str, &offset)) {
        return 0;
    }

    if (*(str + offset) == '+' ||  myIsCharNum(*(str + offset))) {
        flag = POS;
    } else {
        flag = NAG;
    }

    if (*(str + offset) == '+' || *(str + offset) == '-') {
        offset++;
    }

    offEnd = offset + MySearchOffsetEnd(str + offset);

    for (i = offset; i <= offEnd; i++) {
        if (!MyOutBandCheck(rev, CHG_CHAR_TO_NUM(str[i]), flag)) {
            if (flag == POS) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }
        rev = rev * TEN + CHG_CHAR_TO_NUM(str[i]);
    }

    if (flag == POS) {
        return rev;
    } else {
        return (0 - rev);
    }
}