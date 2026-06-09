
先统计每一行和每一列出现B的次数，孤独像素 必定满足l[i] == 1 && r[j] == 1，i行j列满足后，i行和j列不可能有其他点满足，否则 该像素不满足 “孤独”的条件。因此，找到一个之后需要将l[i]++，r[j]++避免下次再次被访问。
```
int findLonelyPixel(char **picture, int pictureSize, int *pictureColSize)
{
    int i, j;
    int count = 0;
    int l[pictureSize];
    int r[pictureColSize[0]];
    for (i = 0; i < pictureSize; i++) {
        l[i] = 0;
    }
    for (j = 0; j < pictureColSize[0]; j++) {
        r[j] = 0;
    }
    for (i = 0; i < pictureSize; i++) {
        for (j = 0; j < pictureColSize[0]; j++) {
            if (picture[i][j] == 'B') {
                l[i]++;
                r[j]++;
            }
        }
    }
    for (i = 0; i < pictureSize; i++) {
        for (j = 0; j < pictureColSize[0]; j++) {
            if (l[i] == 1 && r[j] == 1) {
                count++;
                //下一次不统计已经统计的行和列
                l[i]++;
                r[j]++;
            }
        }
    }
    return count;
}
```
