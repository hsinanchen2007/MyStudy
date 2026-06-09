### 解题思路一 暴力遍历
    /*
     * 暴力遍历
     *
     * 首先定义哈希表存储deck中的数字及对应出现的次数。
     * 每个数对应出现的次数必须整除分组长度X才满足条件，所以需要再确定每个分组的长度X，
     * 长度X的取值范围为2到哈希表中的最小次数N，同时长度X也必须整除N，才能正确分组。
     * 接着就是确定哈希表中每个数的出现次数是否被X整除：
     * 1. 如果不能整除即退出当前遍历，更新分组长度继续判断；
     * 2. 如果整个哈希表中的次数都能整除，则返回true。
     * */
### 代码

```cpp
bool hasGroupsSizeX(std::vector<int> &deck) {
    if (deck.empty() || deck.size() < 2) {
        return false;
    }

    // 存储数组中每个数字对应出现的次数到哈希表中
    std::unordered_map<int, int> unorderedMap;
    for (int d : deck) {
        unorderedMap[d]++;
    }

    // 计算分组长度的上限，
    // 即哈希表中最小的出现次数
    int N = unorderedMap[deck[0]];
    for (auto iter : unorderedMap) {
        if (N > iter.second) {
            N = iter.second;
        }
    }

    // 寻找合适的分组长度X
    for (int X = 2; X <= N; X++) {
        // 剪枝：分组长度X必须整除最小出现次数
        if (N % X == 0) {
            // 判断是否全部整除
            bool flag = 1;

            // 遍历哈希表
            for (auto iter : unorderedMap) {
                // 判断分组长度X是否整除哈希表中出现次数
                if (iter.second % X != 0) {
                    // 如果有一个不整除，则退出循环，
                    // 更新分组长度X，重新判断
                    flag = 0;
                    break;
                }
            }

            // 分组长度X整除全部哈希表中的出现次数
            if (flag) {
                return true;
            }
        }
    }

    return false;
}
```

### 解题思路二 最大公约数
    /*
     * 最大公约数
     *
     * 由暴力法可知，满足条件的分组长度必然是数字对应出现次数的约数，
     * 暴力法即是判断是否该分组长度为所有数字出现次数的约数。
     * 因此可以直接计算哈希表中每个数字出现次数的最大公约数，最大公约数必然满足条件。
     * 如果最大公约数大于1则返回true。
     * */
### 代码

```cpp
bool hasGroupsSizeX2(std::vector<int> &deck) {
    if (deck.empty() || deck.size() < 2) {
        return false;
    }

    // 存储数组中每个数字对应出现的次数到哈希表中
    std::unordered_map<int, int> unorderedMap;
    for (int d : deck) {
        unorderedMap[d]++;
    }

    // 计算哈希表中出现次数的最大公约数
    int gcdNum = unorderedMap[deck[0]];
    for (auto iter : unorderedMap) {
        gcdNum = gcd(gcdNum, iter.second);
    }

    // 如果公约数大于1则返回true
    return (gcdNum > 1);
}

int gcd(int a, int b) {
    // 使用辗转相除法求最大公约数
    return a == 0 ? b : gcd(b % a, a);
}
```