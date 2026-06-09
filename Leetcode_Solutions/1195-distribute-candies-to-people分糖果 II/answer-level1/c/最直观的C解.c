

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *ret = malloc(sizeof(int)*num_people);
    *returnSize = num_people;
    int i;
    int allotNum = 1;
    for(i=0;i<num_people;i++)
    {
        ret[i] = 0;
    }
    while(candies>0)
    {
        for(i=0;i<num_people;i++)
        {
            if(candies>allotNum)	
            {
                ret[i] += allotNum;
                candies -= allotNum;	
            }
            else
            {
                ret[i] += candies; 
                candies -= candies;
            }
            allotNum++;
        }
    }
    return ret;
}
