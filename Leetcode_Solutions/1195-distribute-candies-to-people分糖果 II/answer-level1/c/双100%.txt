
![image.png](https://pic.leetcode-cn.com/16afd4a619c3771676d834e004a76b974a7f2fd91b802a1ffda37df478d28e4d-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int* distributeCandies(int candies, int num_people, int* returnSize){
    int *cand;
    int temCand = 0;
    int i = 0;
    if(num_people == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    cand = (int *)malloc(sizeof(int) * num_people);
    (void)memset(cand, 0, sizeof(int) * num_people);
    
    while(candies) {
        temCand = MIN(candies, (temCand++));
        cand[i % num_people] += temCand;
        candies -= temCand;
        i++;
    }
    *returnSize = num_people;
    return cand;
}
```