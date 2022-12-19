**思路** 
观察可发现，R可以右移，L可以左移，所以如果end字符串中R的位置相对原位置是右移，
L的位置相对原位置左移，且R和L的相对位置不变，即原来R在左L在右，移动后也是这种
关系。 那就可以返回true，否则返回false

```

bool canTransform(char * start, char * end){
    int len = strlen(start);
    int *rPosition = (int *)malloc(len * sizeof(int));
    int *lPosition = (int *)malloc(len * sizeof(int));
    int rNum = 0, lNum = 0;

    int *prePos = (int *)malloc(len * sizeof(int));
    /* 记录R和L的初始位置 */
    for (int i = 0; i < len; i++) {
        if (start[i] == 'R') {
            rPosition[rNum] = i;
            rNum++;
        } else if (start[i] == 'L') {
            lPosition[lNum] = i;
            prePos[lNum] = rNum;
            lNum++;
        }
    }
    if (rNum + lNum == len && strcmp(start, end) != 0) {
        return false;
    }
    /* 校验位置的改动是否合规 */
    int rIdx = 0, lIdx = 0;
    for (int i = 0; i < len; i++) {
        if (end[i] == 'R') {
            if (rPosition[rIdx] <= i) {     // R右移0
                rIdx++;
            } else {
                return false;
            }
        } else if(end[i] == 'L') {
            if (rIdx != prePos[lIdx]) {
                return false;
            }
            if (lPosition[lIdx] >= i) {      // L左移
                lIdx++;
            } else {
                return false;
            }
        }
    }
    if (rNum != rIdx || lNum != lIdx) {
        return false;
    }
    return true;
}
```

