int myAtoi(char * str){
    int len = strlen(str);
    long val = 0;
    int flag = 1;
    bool hasNum = false;
    bool hasFlag = false;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            if(hasNum){
                break;
            }else if (hasFlag) {
                return 0;
            }
            continue;
        }else if (str[i] == '-' || str[i] == '+') {
            if(hasNum){
                break;
            }else if (hasFlag) {
                return 0;
            }
            hasFlag = true;
            if (str[i] == '-') {
                flag = -1;
            }
        }else if (str[i] >= '0' && str[i] <= '9'){
            hasNum = true;
            val = (val * 10) + (str[i] - '0');
            if (val >  2147483647) {
                break;
            }
        }else
        {
            break;
        }
    }
    val = val * flag;
    if (val > 2147483647) {
        val = 2147483647;
    }else if (val < -2147483648) {
        val = -2147483648;
    }
    return (int)val;
}