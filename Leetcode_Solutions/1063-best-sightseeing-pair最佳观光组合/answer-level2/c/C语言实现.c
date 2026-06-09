`#define MAX(A, B) ((A) > (B)) ? (A) : (B)

int maxScoreSightseeingPair(int* A, int ASize)
{
    int ret = 0;
    int maxI = A[0];

    for (int j = 1; j < ASize; j++) {
        ret = MAX(ret, maxI + A[j] - j);
        maxI = MAX(maxI, A[j] + j);
    }
    return ret;
}`