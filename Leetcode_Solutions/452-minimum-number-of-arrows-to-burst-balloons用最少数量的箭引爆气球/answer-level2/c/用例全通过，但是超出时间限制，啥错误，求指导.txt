typedef struct MyPointStruct {
    int x;
    int y;
}PointStruct;

/* 根据x 从小到大排序 */
void MaoPaoSort(PointStruct* pointArr, int len)
{
    PointStruct tmp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (pointArr[j].x > pointArr[j + 1].x) {
                tmp.x = pointArr[j].x;
                tmp.y = pointArr[j].y;

                pointArr[j].x = pointArr[j + 1].x;
                pointArr[j].y = pointArr[j + 1].y;

                pointArr[j + 1].x = tmp.x;
                pointArr[j + 1].y = tmp.y;
            }
        }
    }
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    PointStruct* pointArr;
    int i;
    int startIndex;
    int endIndex;
    int count;
    if (!points || !pointsColSize) {
        return -1;
    }
    if (pointsSize < 2) {
        return pointsSize;
    }

    pointArr = (PointStruct*)malloc(sizeof(PointStruct) * pointsSize);
    if (!pointArr) {
        return -1;
    }

    for (i = 0; i < pointsSize; i++) {
        pointArr[i].x = points[i][0];
        pointArr[i].y = points[i][1];
    }

    MaoPaoSort(pointArr, pointsSize);

    startIndex = pointArr[0].x;
    endIndex = pointArr[0].y;
    count = 1;

    for (i = 1; i < pointsSize; i++) {
        if (pointArr[i].x <= endIndex) {
            startIndex = pointArr[i].x;
        } else {
            count++;
            startIndex = pointArr[i].x;
            endIndex = pointArr[i].y;
        }

        if (pointArr[i].y < endIndex) {
            endIndex = pointArr[i].y;
        }

    }
    free(pointArr);
    return count;
}


报错：
提交记录
43 / 43 个通过测试用例
状态：超出时间限制

这是啥错误，求指导
