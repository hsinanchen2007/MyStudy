/*数组边界维持比较复杂
*/
#define MAXSIZE 3
struct Node {
    int* arr;
    int arrSize;
};
void Sort(struct Node* obj, int target) {
    int flag = 0;
    int i, temp;
    if (obj->arrSize < MAXSIZE) {
        for (i = MAXSIZE - obj->arrSize; i < MAXSIZE; i++) {
            if (target == obj->arr[i]) return;
            if (target < obj->arr[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) temp = MAXSIZE;
        else temp = i;
        for (int j = MAXSIZE - obj->arrSize; j < temp; j++) {
            obj->arr[j - 1] = obj->arr[j];
        }
        obj->arr[temp - 1] = target;
        (obj->arrSize)++;
    } else {
        for (i = 0; i < MAXSIZE; i++) {
            if (target == obj->arr[i]) return;
            if (target < obj->arr[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) temp = MAXSIZE;
        else temp = i;
        for (int j = 1; j < temp; j++) {
            obj->arr[j - 1] = obj->arr[j];
        }
        if (temp > 0) obj->arr[temp - 1] = target;
    }
}
int thirdMax(int* nums, int numsSize) {
    struct Node* obj = malloc(sizeof(struct Node));
    obj->arr = malloc(sizeof(int) * MAXSIZE);
    obj->arrSize = 0;
    for (int i = 0; i < numsSize; i++) {
        Sort(obj, nums[i]);
    }
    if (obj->arrSize < MAXSIZE) return obj->arr[MAXSIZE - 1];
    return obj->arr[0];
}