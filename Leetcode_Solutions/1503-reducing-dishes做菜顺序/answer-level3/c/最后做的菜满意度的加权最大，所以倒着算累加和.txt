```
int Compare(const void * elem1,const void * elem2){
    int e1 = *(int*)elem1;
    int e2 = *(int*)elem2;
    if(e1 < e2) {
        return 1;
    }

    return -1;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize){
    qsort(satisfaction, satisfactionSize, sizeof(int), Compare);
    if(satisfaction[0] < 0) {
        return 0;
    }
    
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < satisfactionSize; i++) {
        sum += satisfaction[i];
        if(sum < 0) {
            break;
        }
        ans += sum;
    }
    return ans;
}

```
