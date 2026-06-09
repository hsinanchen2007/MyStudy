假设row[0], row[2], row[4]....都是对的，row[1], row[3]不对的话就去后面查找并交换

```
void change(int* row, int rowSize, int tmp) {
    int i;

    for (i = 0; i < rowSize; i++) {
        if (row[i] == tmp) {
            row[i] = row[0];
            row[0] = tmp;
        }
    }
}

int minSwapsCouples(int* row, int rowSize){
    int i;
    int count = 0;
    int tmp;

    for (i = 0; i < rowSize; i++) {
        if (i % 2 == 0) {
            if (row[i] % 2 == 0) {
                tmp = row[i] + 1;
            } else {
                tmp = row[i] - 1;
            }
        } else {
            if (tmp != row[i]) {
                change(row + i, rowSize - i, tmp);
                count++;
            }
        }
    }

    return count;
}
```
