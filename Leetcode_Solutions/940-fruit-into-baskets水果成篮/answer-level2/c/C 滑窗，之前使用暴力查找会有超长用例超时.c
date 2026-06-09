执行用时 :
112 ms
, 在所有 C 提交中击败了
91.28%
的用户
内存消耗 :
9.4 MB
, 在所有 C 提交中击败了
100.00%
的用户


`#define GETMAX(a, b) (((a) > (b)) ? (a) : (b))
int totalFruit(int* tree, int treeSize)
{
    int left;
    int right;
    int l, r, i;
    int fruitnum = 0;
    int fruitmax = 0;

    // 得到左值
    l = 0;
    left = tree[l];
    
    // 得到右值
    i = l + 1;
    while (i < treeSize) {
        if (tree[i] != left) {
            break;
        }
        i++;
    }
    if (i == treeSize) {
        return treeSize;
    }
    r = i;
    right = tree[r];
    for (i = r + 1; i < treeSize; i++) {
        if ((tree[i] != left) && (tree[i] != right)) {
            // 得到滑窗的大小
            fruitnum = i - l;
            fruitmax = GETMAX(fruitmax, fruitnum);
            // 更新滑窗的左指针
            int j = i - 1;
            int near = tree[j];
            while (j >= l) {
                if (tree[j] != near) {
                    break;
                }
                j--;
            }
            l = j + 1;
            left = near; //调试2 ： 原来使用的right，错误，改成near
            // 更新滑窗的右指针
            r = i;
            right = tree[r];
        }
    }
    fruitnum = i - l;//调试1 ： 原来没有添加，出现错误计数
    fruitmax = GETMAX(fruitmax, fruitnum);
    return fruitmax;
}`

之前使用的暴力查找，导致一个0,1循环的超长用例超时
`typedef struct {
    int type;
    int nums;
}FRUIT;

#define GETMAX(a, b) (((a) > (b)) ? (a) : (b))
int totalFruit(int* tree, int treeSize)
{
    FRUIT fruit1 = {0};
    FRUIT fruit2 = {0};
    int i, j, flag;
        int right = 0;
    int fruitnum = 0;
    int fruitmax = 0;
    for (i = 0; i < treeSize; i++) {
        fruit1.type = tree[i];
        fruit1.nums = 1;
        flag = 1;
        fruit2.nums = 0;
        for (j = i + 1; j < treeSize; j++) {
            if (tree[j] == fruit1.type) {
                fruit1.nums++;
            } else {
                if (flag) {
                    fruit2.type = tree[j];
                    fruit2.nums = 1;
                    right = j;
                    flag = 0;
                } else if (tree[j] == fruit2.type) {
                    fruit2.nums++;
                } else {
                    i = right;
                    i--;
                    break;
                }
            } 
        }
        fruitnum = fruit1.nums + fruit2.nums;
        fruitmax = GETMAX(fruitnum, fruitmax);
    }
    return fruitmax;
}`
