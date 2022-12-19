### 解题思路
此处撰写解题思路

### 代码

```c
// 思路：
// 1. 首先判断第一个非空字符，如果是 + - 或者数字，则可初步判断是有效的
//    然后 判断下一个字符减去'0'，如果是在 0 - 9 之间，则算是有效数字，只不过需要考虑是乘以多少个10
//    那如何考虑呢？result = num + result * 10 ; 
//    eg：4123， 第一个数字为4，即 num = 4，然后result=4+0; result = 1 + 4*10;
//    result = 2 + 41*10; result = 3 + 412*10=4123;

// 2. 那怎么判断是否越界呢？
//    定义一个 long类型的result, 然后将其强转为int后，如果还与 result相等，则说明没越界，
//    若否，则越界；
// long result =0;
// if((int)result != result) // 说明越界了

// 3. *(str+count)的写法与*str[count]啥区别呢？？？这个一定要注意好。写成*str[count]会报错。

int myAtoi(char * str){
    int len = strlen(str);
    if (len == 0 || str == NULL) {
        return 0;
    }
    int count = 0;
    // printf("%d, %d \n",count, len);
    printf("\n =====%c \n",*str);

    while(*(str+count) == ' ') { // *str[count] 是不对的
        count++;
    }
    printf(" count=%d \n",count);
    long result = 0; // 作为最终转换结果
    int flag = 0; // 作为判断超出32位数字的标志
    int num = 0; // 字符串每一位的数字
    if (*(str+count) == '+') { // 有可能是一个正数，也有可能是非数字，比如'+-=-96'
        for(int i = count+1; i < len; i++) {
            if((*(str+i) - '0' < 0) || (*(str+i) - '0' > 9)) {
                return result;
            } else {
                num = *(str+i) - '0';
            }
            result = result * 10 + num;
            if((int)result != result) { // 溢出
                return INT_MAX;
            }
        }
        
    } else if(*(str+count) == '-') { // 有可能是一个负数，也有可能是非数字，比如'-=+96'
        for(int i = count+1; i < len; i++) {
            if((*(str+i) - '0' < 0) || (*(str+i) - '0' > 9)) {
                return 0 - result;
            } else {
                num = *(str+i) - '0';
                 printf("num=%d \n", num);
            }
            result = result * 10 + num;
            if((int)result != result) {
                return INT_MIN;
            }
        }
        result = 0 -result;
    } else if((*(str+count) - '0' >= 0) && (*(str+count) - '0' <= 9)) { // 说明是纯数字
        for(int i = count; i < len; i++) {
            if((*(str+i) - '0' < 0) || (*(str+i) - '0' > 9)) {
                return result;
            } else {
                num = *(str+i) - '0';
                printf("num=%d \n", num);
            }
            result = result * 10 + num;
            if((int)result != result) {
                return INT_MAX;
            }
        }
    } else {
        return 0;
    }
    //判断溢出
    // if ((int)ret != ret) {
    return (int)result;
}
```