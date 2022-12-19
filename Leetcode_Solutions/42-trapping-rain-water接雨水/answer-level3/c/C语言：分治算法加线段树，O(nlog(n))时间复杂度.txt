
总体思路：
1、先找到最高的两个柱子，则可以盛水的容量等于这两个柱子中间的最大容量，减去他们之间每一个柱子占去的容量。记为a
2、对左边区间执行执行第1步操作（递归），找到容量b
3、对右边区间执行第1步操作（递归），找到容量c
4、总容量= a + b + c
假设每次都能快速找到两个柱子，则上述步骤的复杂度为O(n)，每个元素在计算容量时仅需访问一次。
那么问题转换为：如何找到给定区间的最高的两个柱子。这是典型的线段树问题。在线段树中，每次查找最高的两个柱子的复杂度O(log(n))。
因此总的时间复杂度可以控制在O(nlog(n))。
注意，这道题的线段树的元素专门定义了一个区间(interval)的结构体，含有最高柱子和次高柱子两个元素。可以用递归的方式实现线段树的构造函数，以及线段树的查找函数。

#define INFINITE (((long long)1 << 31) - 1)

typedef struct Interval {
    int maxFirst;
    int maxSecond;
} Interval;

typedef struct Node {
    Interval intVal;
    int leftIndex;
    int rightIndex;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* Tree;

Interval CompareTwoIntVal(const int* height, const Interval a, const Interval b)
{
    Interval merge;
    merge.maxFirst = height[a.maxFirst] > height[b.maxFirst] ? a.maxFirst : b.maxFirst;
    if (merge.maxFirst == a.maxFirst) {
        if (a.maxSecond == -1) {
            merge.maxSecond = b.maxFirst;
        } else {
            merge.maxSecond = height[a.maxSecond] > height[b.maxFirst] ? a.maxSecond : b.maxFirst;
        } 
    } else {
        if (b.maxSecond == -1) {
            merge.maxSecond = a.maxFirst;
        } else {
            merge.maxSecond = height[a.maxFirst] > height[b.maxSecond] ? a.maxFirst : b.maxSecond;
        }
    }
    return merge;
}


Tree InitSegTree(int* height, int start, int end)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->leftIndex = start;
    node->rightIndex = end;    
    if (start == end) {
        node->left = NULL;
        node->right = NULL;
        node->intVal.maxFirst = start;
        node->intVal.maxSecond = -1;
        return node;
    }
    int mid = start + (end - start) / 2;
    node->left = InitSegTree(height, start, mid);
    node->right = InitSegTree(height, mid + 1, end);
    node->intVal = CompareTwoIntVal(height, node->left->intVal, node->right->intVal);
    return node;
}


Interval FindMax(int* height, Tree segTree, int left, int right)
{
    if (left <= segTree->leftIndex && right >= segTree->rightIndex) {
        return segTree->intVal;
    }
    if (right <= segTree->left->rightIndex) {
        return FindMax(height, segTree->left, left, right);
    }
    if (left >= segTree->right->leftIndex) {
        return FindMax(height, segTree->right, left, right);
    }
    Interval intValLeft = FindMax(height, segTree->left, left, segTree->left->rightIndex);
    Interval intValRight = FindMax(height, segTree->right, segTree->right->leftIndex, right);
    return CompareTwoIntVal(height, intValLeft, intValRight);
}

long long CalcArea(int* height, Tree segTree, int left, int right)
{
    if (right - left <= 1) {
        return 0;
    }
    Interval intVal = FindMax(height, segTree, left, right);
    int minIndex = intVal.maxFirst < intVal.maxSecond ? intVal.maxFirst : intVal.maxSecond;
    int maxIndex = minIndex == intVal.maxFirst ? intVal.maxSecond : intVal.maxFirst;
    long long area = height[intVal.maxSecond] * (maxIndex - minIndex - 1);
    for (int i = minIndex + 1; i <= maxIndex - 1; i++) {
        area -= height[i];
    }
    area += CalcArea(height, segTree, left, minIndex);
    area += CalcArea(height, segTree, maxIndex, right);    
    return area;
}

int trap(int* height, int heightSize)
{
    if (heightSize <= 1) {
        return 0;
    }
    Tree segTree = InitSegTree(height, 0, heightSize - 1);
    long long area = CalcArea(height, segTree, 0, heightSize - 1);
    return area > INFINITE ? INFINITE : area;
}