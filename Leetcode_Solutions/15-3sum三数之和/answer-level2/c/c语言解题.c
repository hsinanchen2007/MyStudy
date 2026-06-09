1、先对数组进行排序，从小到大；
2、最外层由最小值遍历到0，可以减小一半的计算量；
3、剩下的2个数，由两头开始遍历，一直到两个数碰到一起；


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int exist(int *p_nums, int left, int right, int remain){
    if(p_nums[left] == remain || p_nums[right] == remain) 
        return true;
    int middle = 0;

    if(right - left <= 1){
        return false;
    }
    else{
        middle = (left + right)/2;
        if(p_nums[middle] == remain){
            return true;
        }
        else if(p_nums[middle] > remain){
            return exist(p_nums, left, middle, remain);
        }
        else{
            return exist(p_nums, middle, right, remain);
        }
    }
}
 int comp(const void * a, const void * b){
     return *(int *)a - *(int *)b;
 }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ret = NULL;
    if(nums==NULL || numsSize < 3) {
        *returnSize = 0;
        ret = (int **)malloc(sizeof(int *));
        *returnColumnSizes = (int *)malloc(sizeof(int));
        return ret;
    }
    int i=0;

    int ret_index = 0;

    // 申请新地址，存放输入数组，并进行排序
    int *p_nums = (int *)malloc(sizeof(int) * numsSize);
    for(i=0; i<numsSize; i++){
        p_nums[i] = nums[i];
    }
    qsort(p_nums, numsSize, sizeof(int), comp);

    if((p_nums[0] + p_nums[1] + p_nums[2] > 0)
    || (p_nums[numsSize -1] + p_nums[numsSize -2] + p_nums[numsSize -3] <0)
    || (p_nums[0] > 0 || p_nums[numsSize-1] < 0)){
        *returnSize = 0;
        return ret;       
    }


    // 分别计算几个值得取值范围
    int first_left = 0, first_right = 0;
    int thirt_left = 0, thirt_right = numsSize-1;

    for(i=0; i<numsSize-1; i++){
        if(p_nums[i] < 0 && p_nums[i+1] >= 0){
            first_right = i;
            break;
        }
    }
    for(i=numsSize-1; i>0; i--){
        if(p_nums[i] > 0 && p_nums[i-1] <= 0){
            thirt_left = i;
            break;
        }
    }

    int totalnum = (first_right + 1) * (thirt_right - thirt_left + 1);
    ret = (int **)malloc(sizeof(int *) * totalnum);
    if(ret == NULL) {
        *returnSize = 0;
        ret = (int **)malloc(sizeof(int *));
        return ret;
    }
    int *a = p_nums;
    int *b = &p_nums[1];
    int *c = &p_nums[numsSize -1];
    int tmp = 0;
    int *p_end = c;

    for(a=p_nums; a + 2 <= p_end && *a <= 0;){
        b = a + 1;
        c = &p_nums[numsSize -1];
        while(b < c){
            tmp = *b + *c + *a;
            if(tmp == 0){
                ret[ret_index] = (int *)malloc(sizeof(int) * 3);
                ret[ret_index][0] = *a;
                ret[ret_index][1] = *b;
                ret[ret_index][2] = *c;
                ret_index++;
                do{
                    b++;
                }while(b < c && *b == *(b - 1));   
                do{
                    c--;
                }while(c>b && *c == *(c+1));                   
            }
            else if(tmp < 0){
                do{
                    b++;
                }while(b < c && *b == *(b - 1));   
            }
            else{
                do{
                    c--;
                }while(c>b && *c == *(c+1));
            }
        }
        do{
            a++;
        }while(a < (p_nums + numsSize -1) && *a == *(a - 1));
    }

    *returnColumnSizes = (int *)malloc(sizeof(int)*ret_index);
    for(i=0; i<ret_index; i++){
        (*returnColumnSizes)[i] = 3;        
    }
    *returnSize = ret_index;

    return ret;
}