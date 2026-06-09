int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

     int * map = (int *) malloc(sizeof(int) * 9999);
    memset(map, 0, sizeof(int) * 9999);

    int *res = (int *) malloc(sizeof(int) * (nums1Size+nums2Size));
    memset(res, 0, sizeof(int) *  (nums1Size+nums2Size));

    int k = 0;

    for(int i = 0; i < nums1Size; i++)
    {
        map[nums1[i]]++;
    }

    for(int i = 0; i < nums2Size; i++)
    {
        if(map[nums2[i]] != 0)
        {
            res[k++] = nums2[i];
            map[nums2[i]] = 0;
        }
            
    }
    *returnSize = k;
    return res;
}
