int reverse(int x){
        int uRet = 0;
        int flag = 1;
        int tmp = x;
        if (tmp < 0) {
            if (tmp == -2147483648) {
                return 0;
            }
            flag = -1;
            tmp = tmp * (-1);
        }

        int Stack[10000];
        int top = -1;
        int pos = 1;
        int modNum = tmp;
        if (tmp == 0) {
            return 0;
        }
        while (modNum > 0) {
            Stack[++top] = modNum % 10;
            modNum = modNum / 10;
        }

        int i;

        if (top == 9 && Stack[0] > 2) {
            return 0;
        }
        for (i = top; i >= 0; i--) {
            uRet += Stack[i] * pos;
            if (top == 9 && i == 1 && uRet > 147483647 && Stack[0] >= 2) {
                return 0;
            }
            if (pos != 1000000000) {
                pos = pos * 10;
            }       
        }
        uRet = uRet * flag;

        return uRet;
}