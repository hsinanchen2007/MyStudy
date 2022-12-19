```
void calTranslateNum(int num, int* count)
{
    if (num / 10 == 0) { /* num < 10 一种可行的分配方式走完，计数+1 */
        *count = *count + 1;
        return;
    }

    if (num % 100 < 26 && num % 100 >= 10) { /* 当除100的余数大于等于10且小于26时，该余数（两位数）可以翻译成字母 */
        calTranslateNum(num / 100, count);
    }
    calTranslateNum(num / 10, count); /* 一位数都可以翻译成字母 */
} 

int translateNum(int num){
    int count = 0;
    calTranslateNum(num, &count);
    return count;
}
```
