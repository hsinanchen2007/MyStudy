方法1：
中序遍历二叉树，得到两个排序后的数组，然后两个for循环嵌套匹配：运行时间：76ms/14MB
int r1[5000];
int r2[5000];
int ind = 0;

void getData(struct TreeNode * root, int *r)
{
    if (root->left) {
        getData(root->left, r);
    }
    r[ind++] = root->val;
    if (root->right) {
        getData(root->right, r);
    }
}

bool cmpDataSum(int *r1, int len1, int *r2, int len2, int target)
{
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (r1[i] + r2[j] == target) {
                return true;
            } else if (r1[i] + r2[j] > target) {
                break;
            }
        }
    }
    return false;
}
bool twoSumBSTs(struct TreeNode* root1, struct TreeNode* root2, int target){
    int len1, len2;
    
    ind = 0;
    getData(root1, r1);
    len1 = ind;

    ind = 0;
    getData(root2, r2);
    len2 = ind;

    return cmpDataSum(r1, len1, r2, len2, target);
}

改进：考虑到数组是有序的，比较的时候不需要每次加1，可以采用二分思想：20ms/14MB
改进部分代码如下所示：
bool cmpDataSum(int *r1, int len1, int *r2, int len2, int target)
{
    int tmp;
    int index;
    int len2Tmp;

    len2Tmp = len2;
    for (int i = 0; i < len1; i++) {
        len2 = len2Tmp;
        for (int j = 0; j < len2; j = index + 1) {  
            index = 0;
            if (r1[i] + r2[j] == target) {
                return true;
            } else if (r1[i] + r2[j] > target) {
                //printf("11j= %d len2 = %d\n", j, len2);
                break;
            } else if (r1[i] + r2[j] < target) {
                tmp = (j + len2) / 2;
                if (r1[i] + r2[tmp] == target) {
                    return true;
                } else if (r1[i] + r2[tmp] > target) {
                    len2 = tmp;
                    index = j;
                } else {
                    index = tmp;
                }
            }
            //printf("j= %d index = %d len2 = %d\n", j, index, len2);
        }
    }
    return false;
}

数组的使用：
    考虑将两个5000字节数组改为动态申请，消耗资源如下：28ms/14.5MB；也就是时间增多了，但是内存减少了，这里的内存应该主要是指全局使用，不包括栈。