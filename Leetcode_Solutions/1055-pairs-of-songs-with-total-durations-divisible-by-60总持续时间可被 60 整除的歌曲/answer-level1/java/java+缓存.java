第一次自然想到双重for循环计算每一个数的结果，时间复杂度，O(N^2),超时。仔细看数据，歌曲时长最多为500分钟，而数据最多有6000组，所以6000组数据中必然有大量的重复数据，所以很自然的想到用501大小的数组存储每一种时长歌曲的计算结果，具体代码如下，时间复杂度O(500*N),虽然没其他人解答高效，但是非常容易理解
```
class Solution {
    // 缓存1-500分钟歌曲对应的结果
    int[] result = new int[501];

    public int numPairsDivisibleBy60(int[] time) {
        Arrays.fill(result, 0);
        int total = 0;
        for (int i = 0; i < time.length; i++) {
            if (result[time[i]] == 0) {
                int count = 0;
                for (int j = 0; j < time.length; j++) {
                    if (i != j) {
                        if ((time[i] + time[j]) % 60 == 0) {
                            count++;
                        }
                    }
                }
                result[time[i]] = count;
            }
            total += result[time[i]];
        }

        // 注意结果要除以2
        return total / 2; 
    }

}
```
