一共n位，0~9 10个数字可用。
1、n大于10的情况忽略，因为只有10个数字，位数大于10的话，肯定是有重复数字的。
2、没有前导零的情况：前面位用一个数字，后面位就少一个数字可用；能够组成的各位数字不同的整数个数有 9 * 8 * 7... 个,即递归把各位可用数字个数相乘就是在此种情况能够组成的整数个数了。
3、有前导零的情况：当前位如果还是选择用0，后面位还是可以多一些数字(10个)可用，因为前导零不占用数字，则就只看后面位组成整数的个数即可；
                  当前位如果选择非0数字，后面位就少一个数字可用，递归把当前及后续各位可用数字个数相乘就是在此种情况能够组成的整数个数了。

#define MAX_LEN 10
#define MAX_DIGIT 9

int countNumbersWithUniqueDigitsPos(int pos, int cntUsed, bool lead0)
{    
    if (lead0) {
        if (pos == 0) {
            return (MAX_DIGIT + 1);
        }

        int cnt = countNumbersWithUniqueDigitsPos(pos - 1, cntUsed, true);
        cnt += MAX_DIGIT * countNumbersWithUniqueDigitsPos(pos - 1, cntUsed + 1, false);

        return cnt;
    } else {
        if (pos == 0) {
            return (MAX_DIGIT + 1 - cntUsed);
        }

        return (MAX_DIGIT + 1 - cntUsed) * countNumbersWithUniqueDigitsPos(pos - 1, cntUsed + 1, false);
    }
}

int countNumbersWithUniqueDigits(int n){
    int tmp = (n > MAX_LEN) ? MAX_LEN : n;
    if (tmp == 0) {
        return 1;
    }

    return countNumbersWithUniqueDigitsPos(n - 1, 0, true);
}