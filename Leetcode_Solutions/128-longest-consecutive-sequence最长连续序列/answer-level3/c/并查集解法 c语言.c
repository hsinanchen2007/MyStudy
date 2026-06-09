```
int unionserch(int root, int * list)
{
    int son;
    int temp;
    son = root;
    while(root != list[root]) {
        root = list[root];
    }
    while (list[son] != root) {
        temp = list[son];
        list[son] = root;
        son = temp;
    }
    return root;
}

void join(int a, int b, int * list)
{
    int roota;
    int rootb;
    roota = unionserch(a, list);
    rootb = unionserch(b, list);
    if (roota != rootb) {
        list[rootb] = roota;
    }
    
}

int substractvalone(int a, int b)
{
    if ((a + 1) == b)
        return 1;
    if ((b + 1) == a)
        return 1;
    return 0;
}
// 0不存在 1存在
int isExist(int a, int len, int * numlist)
{
    int i;
    if (len == 0) 
        return 0;
    for (i = 0; i < len; i++) {
        if (a == numlist[i])
            return 1;
    }
    return 0;
}
void func(int * numlist, int * numlen, int * nums, int numsSize)
{
    int i;
    int len;
    *numlen = 0;
    for (i = 0; i < numsSize; i++) {
        if (!isExist(nums[i], *numlen, numlist)) {
            len = *numlen;
            numlist[len] = nums[i];
            
            *numlen = len + 1;
        }
    }
}

int longestConsecutive(int* nums, int numsSize){
    
    int i;
    int j;
    int y;
    int numlen = 0;
    int flag;
    int count = 0;
    int counttemp;
    int temp[100];
    int kind = 0;
    if (numsSize == 0)
        return 0;
    
    int numlist[numsSize];
    func(numlist, &numlen, nums, numsSize);
    int list[numlen];

    for (i = 0; i < numlen; i++) {
        list[i] = i;
    }
    for (i = 0; i < (numlen - 1); i++) {
        for(j = i + 1; j < numlen; j++) {
            if (substractvalone(numlist[i], numlist[j])) {
                join(i, j, list);
            }
        }
    }
    for (i = 0; i < numlen; i++) {
        unionserch(i, list);
    }
    for (i = 0; i < numlen; i++) {
        printf("%d ", list[i]);
    }
    for (i = 0; i < numlen; i++) {
        if (isExist(list[i], kind, temp))
            continue;
        counttemp = 0;
        for (j = 0; j < numlen; j++) {
            if (list[i] == list[j]) {
                counttemp++;
            }
        }
        if (counttemp > count) {
            count = counttemp;
        }
        temp[kind] = list[i];
        kind++;
    }

    return count;
        
}
```
