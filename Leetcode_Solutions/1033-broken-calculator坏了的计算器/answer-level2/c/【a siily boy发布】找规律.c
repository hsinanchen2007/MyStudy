```
int brokenCalc(int X, int Y){
    int  tmpX1 = X;
    int  tmpX2 = X;
    int tmpY = Y;
    int count1 = 0;
    int count2 = 0;
    int returnValue = 0;
    int returnCount1 = 0;
    int returnCount2 = 0;

    //case 1
    if (X >= Y) {
        return X - Y;
    }

    //case 2-1:先翻倍再减法
    while (tmpX1 < Y) {
        tmpX1 = tmpX1 * 2;
        count1++;
    }
    returnCount1 = tmpX1 - Y + count1;

    //case 2-2：先减法再翻倍
    if (tmpY % 2 == 0) {
        while(tmpX2 < tmpY) {
            if (tmpY == tmpX2) {
                count2++;
                break;
            }  
            if (tmpY % 2 != 0) {
                tmpY = tmpY + 1;
                count2++;
            } else {
                tmpY = tmpY / 2;
                count2++;
            }
            //printf("case 2-2-1: count2: %u, tmpY: %u\n", count2, tmpY);
        }
        returnCount2 = tmpX2 - tmpY + count2;
    } else {
        tmpY = tmpY + 1;
        while(tmpX2 < tmpY) {
            if (tmpY == tmpX2) {
                count2++;
                break;
            }  
            if (tmpY % 2 != 0) {
                tmpY = tmpY + 1;
                count2++;
            } else {
                tmpY = tmpY / 2;
                count2++;
            }
            //printf("case 2-2-2: count2: %u, tmpY: %u\n", count2, tmpY);
        }
        returnCount2 = tmpX2 - tmpY + count2 + 1;
    }

    //printf("returnCount1: %u, returnCount2: %u\n", returnCount1, returnCount2);

    returnValue = returnCount1 >= returnCount2 ? returnCount2 : returnCount1;

    return returnValue;
}
```
