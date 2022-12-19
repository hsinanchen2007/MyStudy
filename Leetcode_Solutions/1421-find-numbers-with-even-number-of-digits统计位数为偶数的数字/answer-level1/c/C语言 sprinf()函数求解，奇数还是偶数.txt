
1. int sprintf(char *str, const char *format, ...)函数：str是指向字符数组的指针，后面可以根据%s%c%d等格式，来写到str中
2. 如果成功，则返回写入的字符总数，不包括字符串追加在字符串末尾的空字符。如果失败，则返回一个负数。

```
int findNumbers(int* nums, int numsSize){
    int count = 0,len = 0;

    char *s =(char *)malloc(sizeof(int)*(501)) ;

    for(int i = 0;i<numsSize; i++){

        //sprintf的第一个参数是char *str型的,如果成功，则返回写入的字符总数，不包括字符串追加在字符串末尾的空字符。如果失败，则返回一个负数。
        len = sprintf(s,"%d",nums[i]);

        if(0 == len%2){
            count++;
            *s = "";//还原字符串
            }
        else *s = "";//还原字符串
    }
    return count;
}
```
