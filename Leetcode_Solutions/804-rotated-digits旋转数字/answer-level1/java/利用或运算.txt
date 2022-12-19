```
class Solution {
   
     //0 - 9: 0,1,8 必须和其他好数配合，2，5，6，9 是好数，其余一出现就不是好数
    private int[] sMap = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};

    public int rotatedDigits(int N) {
        int count = 0;

        for (int i = 1; i <= N; i++) {
            if (isGood(i)) {
                count++;
            }
        }
        return count;
    }
    // 0 和任何数或运算都是那个数，-1 和任何数或运算都是 -1
    private boolean isGood(int i) {
        int flag = 0;
        while (i > 0) {
            int mod = i % 10;
            flag |= sMap[mod];
            i /= 10;
        }

        return flag > 0;
    }
}
```