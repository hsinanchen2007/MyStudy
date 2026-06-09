一个数组记录认识别人的人数，一个数组记录认识自己的人数
```
public int findCelebrity(int n) {
    int[] knowOther = new int[n];
    int[] otherKnow = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (knows(i, j)) {
                otherKnow[j]++;
                knowOther[i]++;
            }
        }
    }
    for (int i = 0; i < otherKnow.length; i++) {
        if (otherKnow[i] == n && knowOther[i] == 1) {
            return i;
        }
    }
    return -1;
}
```
