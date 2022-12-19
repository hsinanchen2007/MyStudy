```
bool hasGroupsSizeX(int* deck, int deckSize){
    if (deckSize == 1) {
        return false;
    }

    int hashMap[10000] = {0};
    int i, j;
    for (i = 0; i < deckSize; i++) {
        hashMap[deck[i]]++;
    }
    if (hashMap[deck[0]] == deckSize) {
        return true;
    }
    // X可取的范围：X <= deckSize / 2 || X == deckSize(前提是所有数相同)
    //上面已经判断过，因此下面的for循环的次数可以降低到deckSize / 2
    for (i = 2; i <= deckSize / 2; i++) {
        for(j = 0; j < 10000; j++) {
            if (hashMap[j] % i != 0) {
                break;
            }
        }
        if (j == 10000) {
            return true;
        }
    }
    return false;
}
```
