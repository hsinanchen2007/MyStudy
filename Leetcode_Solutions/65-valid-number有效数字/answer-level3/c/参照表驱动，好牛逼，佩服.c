`int make_state(char c) {
    switch(c) {
        case ' ':
            return 0;
        case '-':
        case '+':
            return 1;
        case '.' :
            return 3;
        case 'e':
        case 'E':
            return 4;
        default:
            if (c >= '0' && c <= '9') {
                return 2;
            }
            else {
                return 5;
            }
    }
}
bool isNumber(char * s){
    int state = 0;
    int final[9] = {0, 0, 0, 1, 0, 1, 1, 0, 1};
    int transfer[9][6] = {
        {0,   1, 6, 2, -1, -1},
        {-1, -1, 6, 2, -1, -1},
        {-1, -1, 3, -1, -1, -1},
        {8, -1, 3, -1, 4, -1},
        {-1, 7, 5, -1, -1, -1},
        {8, -1, 5, -1, -1 ,-1},
        {8, -1, 6, 3, 4 ,-1},
        {-1, -1, 5, -1, -1 ,-1},
        {8, -1, -1, -1, -1 ,-1},
    };   
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        state = transfer[state][make_state(s[i])];
        if (state == -1) {
            return 0;
        }
    }

    return final[state];
}`