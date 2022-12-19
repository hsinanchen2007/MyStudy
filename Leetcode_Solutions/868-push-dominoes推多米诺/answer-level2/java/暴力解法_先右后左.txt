顺着题目描述来做，暴力解法，代码量大，但是十分好记和实现，不过运行时间是20ms，超过了70%，还是很不错的：先从头到尾遍历，推倒所有向右倒的，中间有两种情况需要处理：R..L(RRLL)/R...L(RR.LL)，处理一下.是奇数还是偶数个就可以，然后再从尾到头遍历，推倒所有向左倒的，同样有两种情况需要处理：L.L(LLL),L.R(L.R)，如果L后面有R，则不变，如果后面是L或者都是.，那么置为L。
```
    private static  String pushDominoes(String dominoes) {
        char[] domino = dominoes.toCharArray();
        for (int i = 0; i < domino.length; i++) {
            if (domino[i] == 'R') {
                int j = i + 1;
                int sign = 0;
                for (; j < domino.length;) {
                    if (domino[j] == 'R') {
                        sign = 1;
                        break;
                    }
                    if (domino[j] == 'L') {
                        sign = -1;
                        break;
                    }
                    j++;
                }
                if (sign == 1) {
                   for (int k = i + 1; k < j; k++) {
                       domino[k] = 'R';
                   }
                } else if (sign == -1) {
                    int sum = i + j;
                    if (sum % 2 == 0) {
                        for (int k = i + 1; k < sum / 2; k++) {
                            domino[k] = 'R';
                        }
                    } else {
                        for (int k = i + 1; k <= sum / 2; k++) {
                            domino[k] = 'R';
                        }
                    }
                    for (int k = sum / 2 + 1; k < j; k++) {
                        domino[k] = 'L';
                    }
                }
                if (j >= domino.length) {
                    for (int k = i + 1; k < domino.length; k++) {
                        domino[k] = 'R';
                    }
                }
                i = j - 1;
            }
        }
        for (int i = domino.length - 1; i >= 0; i--) {
            if (domino[i] == 'L') {
                int j = i - 1;
                int sign = 0;
                for (;j >= 0;) {
                    if (domino[j] == 'R') {
                        sign = 1;
                        break;
                    }
                    if (domino[j] == 'L') {
                        sign = -1;
                        break;
                    }
                    j--;
                }
                if (sign == -1) {
                    for (int k = j + 1; k < i; k++) {
                        domino[k] = 'L';
                    }
                }
                if (j < 0) {
                    for (int k = 0; k < i; k++) {
                        domino[k] = 'L';
                    }
                }
                i = j + 1;
            }
        }
        return String.valueOf(domino);
    }
```

