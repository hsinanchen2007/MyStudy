### 解题思路
![image.png](https://pic.leetcode-cn.com/03340feca3908c8e86ce68ee0c4a31af26cc87bd28c44d0ddc2f0baa3f396947-image.png)

最笨的方法
首先身高排序，且将所有人的身高设为最大值
然后从最矮(h,k)的开始排，最矮的人左边有k个比他高的人即可，找到位置就放进去

### 代码

```c
void sortArray(int** people, int peopleSize)
{
    int i;
    int j;
    int temp;
    for (i = 0; i < peopleSize; i++) {
        for (j = 0; j < i; j++) {
            if(people[i][0] < people[j][0]) {
                temp = people[i][0];
                people[i][0] = people[j][0];
                people[j][0] = temp;
                temp = people[i][1];
                people[i][1] = people[j][1];
                people[j][1] = temp;
            }
        }
    }
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, 
                       int* returnSize, int** returnColumnSizes)
{
    sortArray(people, peopleSize);
    int** peopleTemp = (int **)calloc(1, peopleSize * sizeof(int*));
    for (int i = 0; i < peopleSize; i++) {
        peopleTemp[i] = (int *)calloc(1, peopleColSize[i] * sizeof(int));
        memset(peopleTemp[i], 0x7F, peopleColSize[i] * sizeof(int));
    }
    
    int cnt;
    for (int i = 0; i < peopleSize; i++) {
        cnt = -1;
        for (int j = 0; j < peopleSize; j++) {
            cnt += ((peopleTemp[j][0] >= people[i][0]));
            if (cnt == people[i][1]) {
                peopleTemp[j][0] = people[i][0];
                peopleTemp[j][1] = people[i][1];
                break;
            }
        }
    }
    *returnSize = peopleSize;
    *returnColumnSizes = peopleColSize;
    return peopleTemp;
}
```