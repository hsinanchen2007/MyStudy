![1D694741-E74E-457A-A786-9E1A83971D8E.jpeg](https://pic.leetcode-cn.com/03ae8c3d481d404293e93223db9147f7a0d1c0cb73c1eebcd37698f28fddce8b-1D694741-E74E-457A-A786-9E1A83971D8E.jpeg)
```
/*
基本算法：对于不完全为 0 的非负整数 a，b，gcd（a，b）表示 a，b 的最大公约数，必然存在整数对 x，y，
使得gcd（a，b）= ax + by。
*/

int SubFuncGCD(int x, int y) {
    int r;
    if (y == 0) {
        return x;
    }
    r = x % y;

    return SubFuncGCD(y, r);
}

bool canMeasureWater(int x, int y, int z){
    if ((z == 0) || (x + y == z)) {
        return true;
    }
    if ((x == 0) && (y == 0)) {
        if (z == 0) {
            return true;
        } else {
            return false;
        }
    }

    //最大公约数
    int gcdNum = SubFuncGCD(x, y);
    //printf("gcdNum: %d\n", gcdNum);

    if (z == 0) {
        return true;
    }

    //return (z == 0) || (z % gcd(x,y) == 0 && x + y >= z);
    if (((z % gcdNum) == 0) && (x + y >= z)) {
        return true;
    } else {
        return false;
    }
}
```

