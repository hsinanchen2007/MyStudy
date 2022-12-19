### 解题思路
给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct htnode{
    int key;
    int val;
    struct htnode * next;
}Node;

void htAdd(Node **nodeHt, int key, int val){
    int keyaddr = key%1000;
    Node *newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->val = val;
    newNode->next = NULL;
    
    if (nodeHt[keyaddr] == NULL) {
        nodeHt[keyaddr] = newNode;
        //printf("1key %d val=%d %p\n", key, val, nodeHt[keyaddr]);
    } else {
        Node * temp = nodeHt[keyaddr];
        //printf("2key %d val=%d\n", key, val);
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

int htGet(Node** nodeHt, int key){
    int keyaddr = key%1000;

    //printf("key=%d nodeptr=%p\n", key, nodeHt[keyaddr]);
    if (nodeHt[keyaddr]) {
        Node * temp = nodeHt[keyaddr];

        while (temp) {
            if (temp->key == key)
                return temp->val;
            temp = temp->next;
        }
    }

    return -1;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int * res = malloc(nums1Size * sizeof(int));
    Node **hashTable = malloc(1000 * sizeof(Node *));
    int i, k = 0;
    int stack[1000] = {0};
 
    memset(hashTable, 0 , 1000 * sizeof(Node *));
    for (i = 0; i < nums2Size; i++) {
        if (k > 0) {
            //printf("stack k=%d nums=%d stack=%d\n", k, nums2[i], stack[k-1]);
            while (k > 0 && nums2[i] > stack[k-1])
                htAdd(hashTable, stack[--k], nums2[i]);
            
        }

        if (i < nums2Size - 1 && nums2[i] < nums2[i+1]) {
            htAdd(hashTable, nums2[i], nums2[i+1]);
        } else {
            stack[k++] = nums2[i];
        }
    }


    for (i = 0; i < nums1Size; i++) {
        res[i] = htGet(hashTable, nums1[i]);
    }
    *returnSize = nums1Size;
    return res;
}
```