
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *ans = (int*)calloc(num_people, sizeof(int));
    int curChild = 0;
    int preCnt = 0;

    while (candies > 0) {
        preCnt++;
        if (preCnt >= candies) {
            ans[curChild] += candies;
            candies = 0;
        } else {
            ans[curChild] += preCnt;
            curChild++;
            candies -= preCnt;
        }
        if (curChild == num_people) {
            curChild = 0;
        }
    }
    *returnSize = num_people;
    return ans;
}