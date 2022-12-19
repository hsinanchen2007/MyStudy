```
bool isPalindrome(int num) {
    if (num < 0) {
        return false;
    }

    long flag = 1;
    while (num / flag != 0) {
        flag *= 10;
    }

    flag /= 10;

    while (flag != 1) {
        if (flag == 0) {
            return true;
        }
        int left = num / flag;
        int right = num % 10;
        if (left != right) {
            return false;
        }

        num = (num - left * flag) / 10;
        flag /= 100;
    }

    return true;
}
```
