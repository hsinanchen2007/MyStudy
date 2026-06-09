### 解题思路
参考别人C++的码，原作链接https://leetcode-cn.com/problems/additive-number/solution/xia-biao-zuo-wei-fen-duan-dian-dfs-by-over-lord/

### 代码

```c
/**
 * get a section of string 'num' from head to tail
 */
char *getNum (char *num, int head, int tail) {
    if (tail >= strlen(num) || head < 0) return NULL;
    char *n = malloc(tail-head+2);
    int index = 0;
    for (; index <= tail-head; index++) {
        n[index] = num[head+index];
    }
    n[index] = '\0';
    return n;
}

/**
 * reverse a given string
 */
char *strReverse(char *s) {
    int x = 0;
    int y = strlen(s)-1;
    while (x < y) {
        char tmp = s[x];
        s[x] = s[y];
        s[y] = tmp;
        x++;y--;
    }
    return s;
}

/**
 * add two integers as parts of array
 * if adding failed then return NULL
 */
char *add(char *num, int i, int j, int k) {
    char *a = getNum (num, i, j);
    char *b = getNum (num, j+1, k);

    // check validity of the two given numbers
    if (a == NULL || b == NULL) return NULL;

    int bigger = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    char *sum = malloc(bigger+1);
    int x = strlen(a)-1;
    int y = strlen(b)-1;
    int z = 0;
    char carry = 0;

    /* add two numbers char by char */
    while (x >= 0 && y >= 0) {
        char tmp = a[x] + b[y] - '0' - '0' + carry;
        carry = 0;
        if (tmp >= 10) {tmp = tmp - 10; carry = 1;}
        sum[z] = '0' + tmp;
        x--; y--; z++;
    }

    /* handle the case when one number has more digit than the other */
    if (x == -1 && y >= 0) {
        while (y >= 0) {
            char tmp = b[y] - '0' + carry;
            carry = 0;
            if (tmp >= 10) {tmp = tmp - 10; carry = 1;}
            sum[z] = '0' + tmp;
            y--; z++;
        }
    } else if (x >= 0 && y == -1) {
        while (x >= 0) {
            char tmp = a[x] - '0' + carry;
            carry = 0;
            if (tmp >= 10) {tmp = tmp - 10; carry = 1;}
            sum[z] = '0' + tmp;
            x--; z++;
        }
    }

    /* handle the case that result is longer than both of given numbers */
    if (carry != 0) {
        sum =  realloc(sum, bigger+2);
        sum[z] = '1';
        z++;
        sum[z] = '\0';
    } else {
        sum[z] = '\0';
    }

    /* get sum in right order */
    sum = strReverse(sum);

    return sum;
}

bool dfs(char *num, int i, int j, int k) {
    int len = strlen(num);
    // if one of the number start with 0 return false
    if ((num[i] == '0' && i != j) || (num[j+1] == '0' && k > j+1)) return false;

    // get the sum of arr[i] ~ arr[j] and arr[j+1] ~ arr[k] as sum
    char *sum = add(num, i, j, k);
    if (sum == NULL) return false;

    // check if there exist a integer n such that arr[i~j] + arr[j+1~k] = arr[k+1~k+n]
    int n = strlen(sum);
    char *next = getNum (num, k+1, k+n);

    if (next == NULL || strcmp(next, sum) != 0) return false;
    else if (k+n == len-1) return true; 
    return dfs(num, j+1, k, k+n); 
}

bool isAdditiveNumber(char * num){
    int i = 0;                                          // i is the starting index
    for (int j = i; j <= strlen(num)/2; j++) {          // j is the middle index
        for (int k = j+1; k <= strlen(num); k++) {      // k is the finishing index
            if (dfs(num, i, j, k)) return true;
        }
    }
    return false;
}
```