```
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int m = nums1Size;  // short_array_len
    int n = nums2Size;  // long_array_len
    int *short_array = nums1; // short_array
    int *long_array = nums2;  // long_array
    int middle;
    int i, j;

    if (nums1Size > nums2Size) {
        short_array = nums2;
        long_array = nums1;
        m = nums2Size;
        n = nums1Size;
    }
    
    int i_min = 0;
    int i_max = m;
    int left;
    middle = (m + n + 1) / 2;
    /*
     *            +------------------------+-----------------------------+
     * short_array|0                  i - 1|i                       m - 1|
     *            +------------------------+-----------------------------+
     *
     *            +----------------------------+-----------------------------+
     * long_array |0                      j - 1|j                       n - 1|
     *            +----------------------------+-----------------------------+
     * 这里核心需要排除的异常情况有两种：
     * 1. short_array[i - 1] > long_array[j]    说明分界线靠左了
     * 2. short_array[i] < long_array[j - 1]   说明分界线靠右了
     * 除此之外的情况就是满足题目条件的
     */
    while (i_min <= i_max) {
        i = (i_min + i_max) / 2;
        j = middle - i;
        if ((i > i_min) && (short_array[i - 1] > long_array[j])) {
            i_max = i - 1;
        } else if ((i < i_max) && (short_array[i] < long_array[j - 1])) {
            i_min = i + 1;
        } else {
            int max_left;
            if (i == 0) {
                /* left_part  = x                                     + (long_array[0] ~ long_array[j - 1]);
                 * right_part = (short_array[0] ~ short_array[m - 1]) + (long_array[j] ~ long_array[n - 1])
                 * 因此left_part和right_part的分界线就是 long_array[j - 1];
                 */
                max_left = long_array[j - 1];
            } else if (j == 0) {
                /* left_part  = (short_array[0] ~ short_array[i - 1]) + x;
                 * right_part = (short_array[i] ~ short_array[m - 1]) + (long_array[0] ~ long_array[n - 1]);
                 * 因此left_part和right_part的分界线就是 short_array[i - 1];
                 */
                max_left = short_array[i - 1];
            } else {
                // 排除以上两种特殊情况后需要在short_array[i - 1]和long_array[j - 1]中挑选较大值
                max_left = MAX(long_array[j - 1], short_array[i - 1]);
            }
            
            if ((m + n) % 2 == 1) {
                return max_left;
            }
            
            int min_right;
            if (i == m) {
                /* left_part  = (short_array[0] ~ short_array[m - 1]) + (long_array[0] ~ long_array[j - 1]);
                 * right_part = x                                     + (long_array[j] ~ long_array[n - 1]);
                 * 因此left_part和right_part的分界线就是long_array[j];
                 */ 
                min_right = long_array[j];
            } else if (j == n) {
                /* left_part  = (short_array[0] ~ short_array[i - 1]) + (long_array[0] ~ long_array[n - 1]);
                 * right_part = (short_array[i] ~ short_array[n - 1]) + x;
                 * 因此left_part和right_part的分界线就是short_array[i];
                 */
                min_right = short_array[i];
            } else {
                // 排除以上两种特殊情况后需要在short_array[i]和long_array[j]中挑选较小值
                min_right = MIN(long_array[j], short_array[i]);
            }
            
            return ((max_left + min_right) / 2.0);
        }
    }

    return 0.0;
}
```
