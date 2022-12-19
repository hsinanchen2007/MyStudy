### 解题思路
此处撰写解题思路
注意两点： 1.最后一个字符长度的处理（有一种场景是只有一个字符）；
          2.数字的处理，大于10的数字处理，C语言处理相对麻烦。
### 代码

```c
int AddNumsToStr(char *str, int *j, int len, int aLen)
{
    int numsLen = 0;
    int nums[5] = {0};
    nums[0] = aLen / 10000;
    nums[1] = (aLen % 10000) / 1000;
    nums[2] = (aLen % 1000) / 100;
    nums[3] = (aLen % 100) / 10;
    nums[4] = aLen % 10;
    for (int i = 0; i < 5; i++) {
        if (numsLen != 0) {
            str[(*j)++] = nums[i] + '0';
        } else {
            if (nums[i] != 0) {
                numsLen = 5 - i;
                //printf("i %d, *j%d len %d\n",i,*j,len);
                if ((numsLen + *j) >= len) {
                    return 0;
                }
                str[(*j)++] = nums[i] + '0';
            }
        }
    }
    return 1;
}

char* compressString(char* S){
    if (S[0] == '\0') return S;
    int len = strlen(S);
    char *str = malloc(sizeof(char) * len);
    char a = S[0];
    int aLen = 0;
    int j = 0;
    str[j++] = a;
    for (int i = 1; i < len + 1; i++) {
        if (S[i] == a) {
            aLen++;
        } else {
            if (AddNumsToStr(str, &j, len, (aLen + 1)) == 0) {
                return S;
            }
            if (i < len) {
                str[j++] = S[i];
                a = S[i];
                aLen = 0;
            }  
        }
    }
    //printf("j=%d str[j-1]=%d\n",j, str[j-1]);
    str[j] = '\0';
    return str;
}
```