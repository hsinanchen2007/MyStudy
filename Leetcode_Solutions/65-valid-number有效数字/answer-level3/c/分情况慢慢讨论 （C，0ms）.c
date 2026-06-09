不难，但是要慢慢讨论各种符号

```
bool isNumber(char* s) {
    bool decimal = false;  // flag of .
    bool neg = false;      // flag of +/-
    bool num = false;      // flag of numbers
    bool esign = false;    // flag of e
    bool finish = false;   // finish: there are spaces after a valid number
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == ' ') {
            if (num || decimal || neg || esign)
                finish = true;
            continue;
        } else if (finish)  // non-space character after "finish", return false
            return false;
        if (s[i] >= '0' && s[i] <= '9') {
            num = true;
        } else if (s[i] == '-' || s[i] == '+') {
            if ((decimal || num || neg || esign) && s[i - 1] != 'e') {  // before e: no double -/+, after e: right after e sign
                return false;
            } else {
                neg = true;
            }
        } else if (s[i] == '.') {
            if (esign || decimal) {  // before e: no double decimal points, after e：forbidden
                return false;
            } else {
                decimal = true;
            }
        } else if (s[i] == 'e') {  // e must after a valid number
            if (!num || esign) {
                return false;
            } else {
                esign = true;
                num = false;
            }
        } else {
            return false;
        }
    }
    return num;
}

```
