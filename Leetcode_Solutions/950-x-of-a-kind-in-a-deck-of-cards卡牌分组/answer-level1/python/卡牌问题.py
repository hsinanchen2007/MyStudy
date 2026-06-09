### 解题思路
统计各张牌的数量，再求最大公约数

### 代码

```c
int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;       //最大公约数 return b? gcd(b,a%b):a ;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int hash[50] = {0};
    int i, tmp = -1;

    for(i = 0;i < deckSize;i++) 
        hash[deck[i]]++;
    for(i = 0;i < 50;i++)
    {
        if(i==0)
            tmp = hash[i];
        tmp = gcd(tmp,hash[i]);
    }
    return tmp > 1 ? true : false;
}


JAVA：
/*
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        // 计数
        int[] counter = new int[10000];
        for (int num: deck) {
            counter[num]++;
        }
        // 求gcd
        int x = -1;
        for(int cnt: counter) {
            if (cnt > 0) {
                x = x == -1? cnt: gcd(x, cnt);
                if (x == 1) {
                    return false;
                }
            }
        }
        return x >= 2;
    }

    private int gcd (int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }
}

python：
class Solution(object):
    def hasGroupsSizeX(self, deck):
        count = collections.Counter(deck)   得到一个类似 4：2  等列表
        N = len(deck)
        for X in xrange(2, N+1):     X为猜想公约数
            if N % X == 0:
                if all(v % X == 0 for v in count.values()):     遍历 all代表遍历是否所有都满足 important！
                    return True
        return False


```