![image.png](https://pic.leetcode-cn.com/c5107226e26fc96dc724283795e0b0372792c0a994df1fb491ab8ed95802dab5-image.png)


```
char * predictPartyVictory(char * senate){
    int len = strlen(senate);
    int r = 0;
    int d = 0;
    int liveR = 0;
    int liveD = 0;
    while (true) {
        r = 0;
        d = 0;
        for (int i = 0; i < len; i++) {
            if (senate[i] == 'R') {
                if (liveR >= liveD) {
                    liveR++;
                }else {
                    liveD--;
                    senate[i] = '#';
                }
                r++;
            }else if (senate[i] == 'D'){
                if (liveD >= liveR) {
                    liveD++;
                }else {
                    liveR--;
                    senate[i] = '#';
                }
                d++;
            }
        }
        //printf("liveR:%d liveD:%d r:%d d:%d\n",liveR,liveD, r, d);
        if (r == 0 || d == 0) break;
    }
    if (r > d) {
        return "Radiant";
    }else {
        return "Dire";
    }
}
```
