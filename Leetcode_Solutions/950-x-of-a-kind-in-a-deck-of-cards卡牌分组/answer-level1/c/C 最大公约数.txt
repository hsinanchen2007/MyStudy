### 解题思路
最大公约数

### 代码

```c
int gcd(int num1, int num2) {
	int mod = num1 % num2;
	if (mod == 0) {
		return num2;
	} else {
		return gcd(num2, mod);
	}
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int *counts = (int *)malloc(sizeof(int) * 10000);
    memset(counts, 0, sizeof(int) * 10000);
    for (int i = 0; i < deckSize; i++) {
        counts[deck[i]]++;
    }
    int currentGCD = 0;
    for (int i = 0; i < 10000; i++) {
        if (counts[i] > 0) {
            if (currentGCD == 0) {
                currentGCD = counts[i];
            } else {
                currentGCD = gcd(currentGCD, counts[i]);
            }
        }
    }
    free(counts);
    return currentGCD >= 2;
}
```