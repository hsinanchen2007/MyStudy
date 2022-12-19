1. 首先，这题一开始先想到的是暴力法。
```
public int numPairsDivisibleBy60(int[] time) {
        int result = 0;
        for (int i = 0; i < time.length; i++) {
            for (int j = i + 1; j < time.length; j++) {
                if ((time[i] + time[j]) % 60 == 0) {
                    result++;
                }
            }
        }
        return result;
    }
```
超时。


2. 看了提示，time数组遍历对60求余。于是，，写出了这样的
```
public int numPairsDivisibleBy60(int[] time) {
        int result = 0;
        for (int i = 0; i < time.length; i++) {
            time[i] %= 60;
        }
        for (int i = 0; i < time.length; i++) {
            for (int j = i + 1; j < time.length; j++) {
                if (time[i] + time[j] == 60 || time[i] + time[j] == 0) {
                    result++;
                }
            }
        }
        return result;
    }
```
依然超时。
以为除法减少变成加法就行，真是好傻。
其实是有优化的，上一个暴力法只通过了31个用例，31 / 34 个通过测试用例，而这个通过了，，，32个！32 / 34 个通过测试用例


3. 最后是用一个数组保存time数组求余后的数量。
```
public int numPairsDivisibleBy60(int[] time) {
        int result = 0;
        int[] mod = new int[60];
        for (int i = 0; i < time.length; i++) {
            mod[time[i] % 60]++;
        }
        for (int i = 1; i < 30; i++) {
            result += mod[i] * mod[60 - i];
        }
        result += (mod[0] * (mod[0] - 1) + mod[30] * (mod[30] - 1)) / 2;
        return result;
    }
```
