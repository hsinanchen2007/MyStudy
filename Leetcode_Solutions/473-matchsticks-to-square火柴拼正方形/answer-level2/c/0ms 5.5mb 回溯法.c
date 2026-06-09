```c []
static int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a; // 逆序排
}

struct info {
    int value;
    int cnt;
};

bool getTarget(int target, struct info *infos, int len, int cur, int sum) {
    // printf("in: target %d, len %d, cur %d, sum %d\n", target, len, cur, sum);
    if (target == sum) {// printf("out true\n");
        return true;
    }
    if (cur >= len) {// printf("out false\n");
        return false;
    }

    for (int i = cur; i < len; i++) {
        if (infos[i].cnt > 0) {
            int tmp = sum + infos[i].value;
            if (tmp > target) {
                continue;
            }
            infos[i].cnt--;
            if (getTarget(target, infos, len, i, tmp)) {// printf("out true\n");
                return true;
            }
            infos[i].cnt++;
        }
    }// printf("out false, no next\n");
    return false;
}


bool makesquare(int* nums, int numsSize){
    if (numsSize < 4) {
        return false;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int ret = true;
    int sum = 0;
    for (int i = 0; i <numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 4) {
        return false;
    }
    int avg = sum / 4; // 边长    
    if (nums[0] > avg) {
        return false;
    }
    struct info *infos = malloc(sizeof(struct info) * numsSize);
    memset(infos, 0, sizeof(struct info) * numsSize);
    int cur = 0;
    infos[0].value = nums[0];    
    for (int i = 0; i <numsSize; i++) {
        if (nums[i] != infos[cur].value) {
            infos[++cur].value = nums[i];
        }
        infos[cur].cnt++;
    } // for (int i = 0; i < cur + 1; i++)printf("value %d, cnt %d\n", infos[i].value, infos[i].cnt);
    for (int i = 0; i < 3; i++) { //试3个，最后一个不用管
        if (!getTarget(avg, infos, cur + 1, 0, 0)) {
            free(infos);
            return false;
        }
        // for (int i = 0; i < cur + 1; i++)printf("value %d, cnt %d\n", infos[i].value, infos[i].cnt);
    }
    free(infos);
    return true;
}
```

