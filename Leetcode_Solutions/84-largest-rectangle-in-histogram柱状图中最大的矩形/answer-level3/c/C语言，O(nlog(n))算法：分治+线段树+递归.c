![largest_rectang.png](https://pic.leetcode-cn.com/d1d49984987bab56691184fc9948fb7b4f251e234c368f0603c96bbf63b7320b-largest_rectang.png)


#define INFINITE (((long long)1) << 31) - 1

int Max(const long long a, const long long b)
{
    long long temp = a > b ? a : b;
    return temp >= INFINITE ? INFINITE : (int)temp;
}

//递归初始化线段树，每个节点表示某一个线段区间的最小的高度的索引。
int InitTree(int* tree, int* heights, int start, int end, int index)
{
    if (start == end) {
        tree[index] = start;
        return tree[index];
    }
    int leftMin = InitTree(tree, heights, start, start + (end - start) / 2, 2 * index + 1);
    int rightMin = InitTree(tree, heights, start + (end - start) / 2 + 1, end, 2 * index + 2);
    tree[index] = heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
    return tree[index];
}

//递归找一个区间内的最小值
//rootStart:树根表示的线段起始点；rootEnd:树根表示的线段代表的终止点，index：树根的下标值
//start:要查找的线段起始点；end：要查找的线段终止点
int FindMin(int* tree, int* heights, int rootStart, int rootEnd, int start, int end, int index)
{
    //查找区间就是树根区间，直接返回树根的值
    if (rootStart == start && rootEnd == end) {
        return tree[index];
    }
    //在左右子树中找相交线段的最小值，取整体最小，则找到目标线段最小值
    int leftEnd = rootStart + (rootEnd - rootStart) / 2;
    int rightStart = leftEnd + 1;
    int leftIndex = index * 2 + 1;
    int rightIndex = leftIndex + 1;
    if (end <= leftEnd) {
        return FindMin(tree, heights, rootStart, leftEnd, start, end, leftIndex);
    }
    if (start >= rightStart) {
        return FindMin(tree, heights, rightStart, rootEnd, start, end, rightIndex);
    }
    int leftMin = FindMin(tree, heights, rootStart, leftEnd, start, leftEnd, leftIndex);
    int rightMin = FindMin(tree, heights, rightStart, rootEnd, rightStart, end, rightIndex);
    return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
}

//求一个区间内的最大面积，基于最矮的点分治计算左边区域和右边区域的最大面积
int MaxArea(int* tree, int* heights, int totalEnd, int start, int end)
{
    if (start > end) {
        return 0;
    }
    //如果区间就是一个点，直接返回
    if (start == end) {
        return heights[start];
    }
    //求解最矮的点*宽
    int index = FindMin(tree, heights, 0, totalEnd, start, end, 0);
    int maxArea = heights[index] * (end - start + 1);
    //分别求解左边区域的最大面积和右边区域的最大面积
    int maxAreaLeft = MaxArea(tree, heights, totalEnd, start, index - 1);
    int maxAreRight = MaxArea(tree, heights, totalEnd, index + 1, end);
    maxArea = Max(maxArea, maxAreaLeft);
    maxArea = Max(maxArea, maxAreRight);
    return maxArea;
}

int largestRectangleArea(int* heights, int heightsSize)
{
    if (heightsSize <= 0) {
        return 0;
    }
    int* tree = (int*)malloc(sizeof(int) * heightsSize * 4);
    tree[0] = InitTree(tree, heights, 0, heightsSize - 1, 0); //递归创建线段树
    return MaxArea(tree, heights, heightsSize - 1, 0, heightsSize - 1);//递归找最大面积
}