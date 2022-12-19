本方法考虑的方面比较多，不是很推荐，但是作为一个思路，share 一下，速度还是很快的。

![image.png](https://pic.leetcode-cn.com/3550a70da6228ba67c5fbd4ff4cd1211010a89ff3efb29d04302cf1c48106150-image.png)

思路：
    1. 和上一个比较，如果是上坡，直接+1.
    2. 如果是下坡，找到下坡的下限，看看下了多少个台阶，够不够挥霍(flag[i-1]一直减1能否变为负数)，如果够，就倒着从1到i(看看倒着上去的i-1是不是比原值更小，如果是，就更新替换)。如果不够，就求个offset，补成正数。
    3. 如果是平路，找到路的尽头，路中间的点都写为1，尾节点，看看是不是到头了或者尾节点后面是上坡，如果满足也设置为1,不满足，就写为和头结点一样的值。

#define printf 
int candy(int* ratings, int ratingsSize){
    int *flag = (int*) malloc(ratingsSize * sizeof(int));
    if (flag == NULL) {
        return 0;
    }
    memset(flag, 0, ratingsSize * sizeof(int));
    flag[0] = 1;
    int ret = flag[0];
    for (int i = 1; i < ratingsSize; ) {
        int j = i;
        if (ratings[i] > ratings[i-1]) {    //if a[i] > a[i+1], ++
            flag[i] = flag[i - 1] + 1;
            ret+=flag[i];
        }else if (ratings[i] < ratings[i-1]) {      //if a[i] < a[i+1], complicated
            int k;
            while (j+1 < ratingsSize && ratings[j+1] < ratings[j]) {    //find the Downhill limit
                j++;
            }
            printf("i: %d, j: %d\r\n", i, j);
            if (j - i + 1 >= flag[i-1]) {                   //if minus one by one will be negative , plus offset to make it be positive
                int offset = j - i + 1 - flag[i-1] + 1;
                printf("offset: %d\r\n", offset);
                k = i;
                ret -= flag[k-1];
                flag[k-1] += offset;
                ret += flag[k-1];
                while (k <= j) {
                    flag[k] = flag[k-1] - 1;
                    ret += flag[k];
                    printf("k：%d, flag[k]: %d\r\n", k, flag[k]);
                    k++;
                }
            } else {    //if minus limit also be positive, each step plus one , from 1.
                k = j;
                while (k >= i) {
                    flag[k] = j - k + 1;
                    ret += flag[k];
                    k--;
                }
            }
            printf("flag[i]: %d, flag[i-1]: %d\r\n", flag[i], flag[i-1]);
            if (flag[i] + 1 < flag[i-1] && ratings[i-2] == ratings[i - 1]) {
                ret -= flag[i-1];
                flag[i-1] = flag[i] + 1;
                ret += flag[i-1];
            }
        }else { //if a[i] == a[j], a little complicated, some boundries scene should be considered.
            while (j+1 < ratingsSize && ratings[j+1] == ratings[j]) {   //find the duration end id
                flag[j] = 1;
                ret += flag[j];
                j++;
            }
            if (j == ratingsSize - 1 || (j + 1 < ratingsSize && ratings[j+1] > ratings[j])) {   //if already last one or after which will be uphill, set to minum 
                flag[j] = 1;
            } else {
                flag[j] = flag[i -1];
            }
            ret += flag[j];
        }
        i = j + 1;
    }

    free(flag);
    return ret;
}

