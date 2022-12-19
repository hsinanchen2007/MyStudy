### 解题思路
1. 最多3 * 3 * 3 * 3=81种可能性，全部遍历
2. 组装成ip后先判断字符总数是否相等，不符合的直接剪枝
3. 然后再将每个ip段字符串转成int型，这里需要注意两点，一是每个IP段需要判断首字母是不是'0'，
"010"/"01"这种都是不合格的ip格式，需要剪枝；二是标准库函数只提供了atoi，可以将char *转int，
但是没有不支持itoa，所以后面将int转char *需要自己实现；
4. 最后判断每个ip是否小于等于255，符合条件了就保存到result里
![image.png](https://pic.leetcode-cn.com/7b842c504ab06dcd8c1a92cecd68a7dfab55557c6c674dae810c8be03462385d-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 char * Ten_to_other(int num,char* str, int radix) 
 {
     const char a[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     char *ptr=str;
     bool negtive = false;
     if(num==0)
     {
         *ptr++ = '0';
         *ptr = '\0';
         return NULL;//直接就退出，不走后面的情况了，不跟后面共用一个return语句。
     }
     if(num<0)
     {
         num *= -1;
         *ptr++ ='-';
         negtive = true;
     }
     while(num) //不能处理num=0的情况
     {
         *ptr++=a[num%radix];
         num /= radix; 
     } 
     *ptr='\0';//此时ptr已经指向字符串结尾，而str仍旧指向字符串开始。
     ptr--;//让ptr指向字符串内容！！
     char *start=(negtive)? str+1:str;//注意此处不能写str++，否则，str不指向保存值的首地址了
     while(start<ptr)
     {
         char tmp=*ptr;
         *ptr=*start;
         *start=tmp;
         ptr--;
         start++;
     }

     return NULL; 
 }

void substr_wxc(char* s, char* substr, int start, int end)
{
    int i, cnt;

    cnt = 0;
    for (i = start; i <= end; i++) {
        substr[cnt++] = s[i];
    }
    substr[cnt] = '\0';

    return;
}

char ** g_Result;
int g_Result_num;
#define MAX_RESULT_NUM    1000

int num_num_get(int num)
{
    if ((num >= 0) && (num <= 9)) {
        return 1;
    } else if ((num >= 10) && (num <= 99)) {
        return 2;
    } else if ((num >= 100) && (num <= 255)) {
        return 3;
    }
    printf("\r\n num is illeage!");
    return 0;
}

void resultget(int* ip_num, char* s)
{
    int i;
    char substr2[4] = {'0'};
    int s_index = 0;
    int num_num;
    for (i = 0; i < 4; i++) {
        num_num = num_num_get(ip_num[i]);
        Ten_to_other(ip_num[i], substr2, 10);
 //       printf("substr2: %s ",substr2);
        strcat(s, substr2);
  //      printf("\r\n num_num=%d",num_num);
        s_index += num_num;
        if (i <= 2) {
            s[s_index] = '.';
            s_index++;
        }
    }
}


char ** restoreIpAddresses(char * s, int* returnSize){
    int a, b, c, d;
    int ip_num[4] = {0};
    int i;
    int s_len = strlen(s);
    char local1[4] = {'0'};
    char local2[4] = {'0'};
    char local3[4] = {'0'};
    char local4[4] = {'0'};
    char** ans;
    int flag;
    char* local_s = NULL;

    ans = malloc(MAX_RESULT_NUM * sizeof(int *));
    memset(ans, 0, MAX_RESULT_NUM * sizeof(char *));
    g_Result = ans;
    g_Result_num = 0;

    for (a = 1; a < 4; a++) {
        for (b = 1; b < 4; b++) {
            for (c = 1; c < 4; c++) {
                for (d = 1; d < 4; d++) {
                    if ((a + b + c + d) == s_len) {
                        flag = 1;

                        memset(local1, 0, 4);
                        memset(local2, 0, 4);
                        memset(local3, 0, 4);
                        memset(local4, 0, 4);
                        substr_wxc(s, local1, 0, a - 1);
                        substr_wxc(s, local2, a, a + b - 1);
                        substr_wxc(s, local3, a + b, a + b + c - 1);
                        substr_wxc(s, local4, a + b + c, a + b + c + d - 1);

                        if ((a > 1) && (local1[0] == '0')) {
                             flag = 0;
                        }
                        if ((b > 1) && (local2[0] == '0')) {
                             flag = 0;
                        }
                        if ((c > 1) && (local3[0] == '0')) {
                             flag = 0;
                        }
                        if ((d > 1) && (local4[0] == '0')) {
                             flag = 0;
                        }

                        /*printf("\r\na=%d b=%d c=%d d=%d",a, b, c, d);
                        printf("\r\n local1=%s",local1);
                        printf("\r\n local2=%s",local2);
                        printf("\r\n local3=%s",local3);
                        printf("\r\n local4=%s",local4);*/

                        ip_num[0] = atoi(local1);
                        ip_num[1] = atoi(local2);
                        ip_num[2] = atoi(local3);
                        ip_num[3] = atoi(local4);

                        for (i = 0; i < 4; i++) {
                            if(ip_num[i] > 255) {
                                flag = 0;
                            }
                        }

                        if (flag == 0) {
                            continue;
                        } else {
                             /*for ( i = 0; i<4; i++) {
                                printf("%d ",ip_num[i]);
                               }
                               printf("\r\n");*/

                            g_Result[g_Result_num] = malloc((s_len + 4) * sizeof(char));
                            local_s = malloc((s_len + 4) * sizeof(char));
                            memset(local_s, 0, (s_len + 4) * sizeof(char));
                            resultget(ip_num, local_s);
                            //printf("\r\n %s", local_s);
                            strcpy(g_Result[g_Result_num], local_s); /* 保存有效子串 */
                            g_Result_num++;
                            free(local_s);
                        }

                    }
                }
            }
        }
    }

 /*   printf("\r\ng_Result_num = %d",g_Result_num);
    printf("\r\n %s ",g_Result[0]);
    printf("\r\n %s ",g_Result[1]);*/

    *returnSize = g_Result_num;
    return g_Result;
}
```