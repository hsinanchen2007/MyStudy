递归+贪心

终止条件：
1.k小于等于0，则返回num
2.num的长度小于等于k，可以全删除，则返回0

递归条件：
1.优先（贪心）找0的位置，如果0前面的数字个数小于等于k，则num=删除0前面所有（含0），k=k-0前面数字的个数，继续递归
  比如：num=10210，k=2，则下一次递归num=210，k=1
2.如果没有0了，从左开始按升序扫描，在扫描出来的所有字符中找到最大数X（也就是最后一个数），则num=删除X后的数，k=k-1，继续递归
  比如：num=1219,k=2,从左开始升序扫描，找到满足升序中数字的最大数2，则下一次递归num=119,k=1


    char * removeKdigits(char * num, int k){
        int i;
        int len = strlen(num);

        if (k <= 0) {
            return num;
        }

        // remove all digits
        if (len <= k || len == 0) {
            num[0] = '0';
            num[1] = 0;
            return num;
        }

        for (i = 0; i < len; i++) {
            if (num[i] - '0' == 0) {
                break;
            }
        }

        // has 0 in the front K digits
        if (i == len - 1 && i <= k) {
            return num + i;
        }
        if (i <= k) {
            return removeKdigits(num + i + 1, k - i); // jump 0
        }

        // remove one biggest digit from front digits
        for (i = 1; i < len; i++) {
            if (num[i] < num[i - 1]) {
                break;
            }
        }
        i--;
        while (i > 0) {
            num[i] = num[i - 1];
            i--;
        }

        return removeKdigits(num + 1, k - 1);
    }