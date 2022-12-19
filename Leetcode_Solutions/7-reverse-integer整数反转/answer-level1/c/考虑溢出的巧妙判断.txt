int reverse(int x){
    int reverseNum = 0;
    int remain;
    int num = x;
    while (num != 0) {
        remain = num % 10;
        
        if ((reverseNum > INT_MAX / 10) || ((reverseNum == INT_MAX / 10) && (remain > 7)) ) {
            return 0;
        }

        if ((reverseNum < INT_MIN / 10) || ((reverseNum == INT_MIN / 10) && (remain < -8)) ) {
            return 0;
        }

        reverseNum = reverseNum * 10 + remain;
        num = num / 10;
    }

    return reverseNum;
}