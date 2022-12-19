为防止int溢出，回文后的数字置为long
```
bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }

    int next = x;
    long ret = 0;
    int temp;

    while (next != 0) {
        temp = next % 10;
        next /= 10;
        ret = ret * 10 + temp;
    }

    if ((x - ret) != 0) {
        return false;
    }
    return true;
}
```
