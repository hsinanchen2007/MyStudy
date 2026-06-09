### 解题思路
此处撰写解题思路

### 代码

```c

int gcd(int a, int b)
{
    int mod = a % b;

    if (mod == 0) {
        return b;
    } else {
        return gcd(b, mod);
    }
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int hash[10001] = { 0 };
    int i;
    int currGcd = -1;
    // 先统计每个数据出现次数
    for (i = 0; i < deckSize; i++) {
        hash[deck[i]]++;
    }

    for (i = 0; i < 10001; i++) {
        if (hash[i] == 0) {
            continue;
        }
        // 如果有数据只出现一次，那么一定不满足要求，直接返回false
        if (hash[i] == -1) {
            return false;
        }
        // 然后再求公约数
        if (currGcd == -1) {
            currGcd = hash[i];
        } else {
            currGcd = gcd(currGcd, hash[i]);
        }
    }
    // 如果最大公约数大于1，满足要求返回true
    if (currGcd > 1) {
        return true;
    }
    return false;
}
```