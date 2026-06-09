bool isPalindrome(int x){
    int weiShu = 1;
    int times = 0;
    int b = x;
    int pre = 0;
    int flag;
    int pop;

    if (x < 0) {
        return false;
    }
    if (x == 0) {
        return true;
    }

    while (x = x / 10) {
        weiShu++;
    }

    if (weiShu == 1) {
        return b;
    }

    times = weiShu / 2;
    flag = (weiShu % 2) ? 1 : 0;
    while (times > 0) {
        pop = b % 10;
        b = b / 10;
        pre = pre * 10 + pop;
        times--;
    }

    if (!flag) {
        return (pre == b);
    } else {
        b /= 10;
        return (pre == b);
    }
}