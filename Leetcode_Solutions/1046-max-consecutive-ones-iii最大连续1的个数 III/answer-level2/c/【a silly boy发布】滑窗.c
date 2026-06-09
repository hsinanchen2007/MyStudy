![42746669-7056-42BE-95E1-836D6C2A3912.jpeg](https://pic.leetcode-cn.com/27f66be511d733f2d363fa0119225a247146bf8d663f8309607ac4c74367105c-42746669-7056-42BE-95E1-836D6C2A3912.jpeg)

```
int longestOnes(int* A, int ASize, int K)
{
    int start = 0;
    int end = 0;
    int returnVal = 0;
    int zeroNum = 0;
    while (end < ASize) {
        while ((end < ASize) && (zeroNum <= K)) {
            if (A[end] == 0) {
                zeroNum++;
            }
            end++;
            if (zeroNum > K) {
                if (returnVal < (end - start - 1)) {
                    returnVal = end - start - 1;
                }
            } else {
                if (returnVal < (end - start)) {
                    returnVal = end - start;
                }   
            }

        }
        //printf("start: %d, end: %d, returnVal: %d， zeroNum： %d\n", start, end, returnVal, zeroNum);
        if (A[start] == 0) {
            zeroNum--;
        }
        start++;
    }

    return returnVal;
}
```
