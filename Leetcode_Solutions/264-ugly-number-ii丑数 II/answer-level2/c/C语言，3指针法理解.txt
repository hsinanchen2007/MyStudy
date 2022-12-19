/*
三指针法的理解,result[0] = 1, 此时，reuslt[0]未与2,3,5相乘,那么result[1] = min(result[0] * 2, result[0] * 3, result[0] *5) 
result[1] = result[0] * 2。此时，result[0]已经与2相乘，还没有和3 5 相成，那么reuslt[2] = min( result[1] * 2, result[0] * 3, result[0] * 5)的最小值
result[2] = reuslt[0] * 3。此时，reuslt[0]已经与2,3相乘,还没有和5相成,那么result[3] 就应该是min(result[1] * 2, reuslt[1] * 3, reusult[0] * 5)的最小值。
每次都是result的值同2 3 5相乘做比较。5走的比2 3要慢，所以存在reulst[0]*5与result[2]*2比较的情况。
*/
#define TRUE 1
#define FALSE 0
int *result;
int min(int a, int b, int c)
{
    int min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
}

void pushUglyNumber(int *result, int n) 
{
    result[0] = 1;
    int j = 1;
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    while (j < n) {
        result[j] = min(result[i2] * 2, result[i3] * 3, result[i5] * 5);
        if(result[j] == result[i2] * 2) {
            i2++;
        } 
        if(result[j] == result[i3] * 3) {
            i3++;
        }
        if(result[j] == result[i5] * 5) {
            i5++;
        }
        j++;
    }
}

int nthUglyNumber(int n) 
{   
    if(n > 1690 || n < 1) {
        return -1;
    }
    result = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        result[i] = 0;
    }
    pushUglyNumber(result, n);
    return result[n-1];
}