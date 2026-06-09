### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(x, y) (x < y ? x : y)
#define LEN 10001

bool hasGroupsSizeX(int* deck, int deckSize){
    int count[LEN] = {0};
    int min = LEN;
    for (int i = 0; i < deckSize; i++) {
        count[deck[i]]++;
    }
    for (int i = 0; i < LEN; i++) {
        if (count[i]) {
           min = MIN(min, count[i]);
        }
    }
    //printf("%d\n", min);
    if (min == 1) {
        return false;
    }
    
    int cnt;
    for (int i = 2; i <= deckSize; i++) {
        cnt = 0;
        if (deckSize % i == 0) {
            for (int j = 0; j < LEN; j++) {
            //每组都有X张牌，X必然是deckSize的公约数
                if (count[j] % i == 0) {
                    cnt++;
                }
            }
        }
        
        if (cnt == LEN) {
            return true;
        }
    }
    return false;
}
```