/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *child = (int *)malloc(sizeof(int) * num_people);
    memset(child, 0, num_people * (sizeof(int)));
    *returnSize = num_people;
    int index = 0;
    int give = 1;
    int res = candies;
    if (res <= give) {
        child[0] = candies;
        return child;
    }

    while (res >= give) {
        child[index] += give;
        res = res - give;
        give++;

        if (res <= 0) {
            break;
        }

        if (res - give < 0) {
            if (index == num_people - 1) {
                child[0] += res;
            } else {
                child[index + 1] += res;
            }
            break;
        }
        if (index == num_people - 1) {
            index = 0;
        } else {
            index++;
        }
    }

    return child;
}