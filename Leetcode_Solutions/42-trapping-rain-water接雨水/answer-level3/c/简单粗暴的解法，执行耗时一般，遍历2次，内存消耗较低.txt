### 解题思路
1、先用第一次遍历找到山顶，可能有多个相同山顶，随便找一个即可。
2、山顶把整个序列分为两部分:左坡[0，山顶] 和 右坡[山顶，末尾]
3、左坡从左往右遍历，找到升序的一个个小山顶，两个升序小山顶之间的值和前一个小山顶求差累加。
4、右坡从右往左遍历，同样找升序的一个个小山顶，小山顶之间值求差累积。
5、注意：左右坡都需要包括山顶，升序小山顶需处理同高的情况。

### 代码

```c
int FindMax(int* height, int size, int* maxIdx)
{
    int max, i;
    max = height[0];
    *maxIdx = 0;
    for (i = 1; i < size; i++) {
        if (height[i] > max) {
            max = height[i];
            *maxIdx = i;
        }
    }
    return max;
}

int CalcSumLeft(int* height, int leftIdx, int leftLen)
{
    int i, last, sum;
    last = height[leftIdx];
    sum = 0;
    for (i = leftIdx + 1; i < leftIdx + leftLen; i++) {
        if (height[i] < last) {
            sum += last - height[i];
        } else {
            last = height[i];
        }
    }
    return sum;
}

int CalcSumRight(int* height, int rightIdx, int rightLen)
{
    int i, last, sum, startIdx;
    startIdx = rightIdx + rightLen - 1;
    last = height[startIdx];
    sum = 0;
    for (i = startIdx - 1; i >= rightIdx; i--) {
        if (height[i] < last) {
            sum += last - height[i];
        } else {
            last = height[i];
        }
    }
    return sum;
}

int trap(int* height, int heightSize){
    int max, maxIdx, sum;
    int leftLen, rightLen, leftIdx, rightIdx;
    if (height == NULL || heightSize < 3) {
        return 0;
    }
    max = FindMax(height, heightSize, &maxIdx);
    leftLen = maxIdx + 1;
    rightLen = heightSize - maxIdx;
    sum = 0;
    if (leftLen > 0) {
        leftIdx = 0;
        sum += CalcSumLeft(height, leftIdx, leftLen);
    }
    if (rightLen > 0) {
        rightIdx = maxIdx;
        sum += CalcSumRight(height, rightIdx, rightLen);
    }
    return sum;
}
```