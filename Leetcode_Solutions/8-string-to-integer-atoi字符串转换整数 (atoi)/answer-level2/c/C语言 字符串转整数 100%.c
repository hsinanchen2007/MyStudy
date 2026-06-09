### 解题思路
此处撰写解题思路

### 代码

```c
// int myAtoi(char * str){
//     int res = 0, sflag = 0, z = 0;
//     for (int i = 0;; i++)
//     {
//         char s = str[i];
//         // printf("[%c]", s);
//         if (s == 32 && sflag == 0)
//         {
//             continue;
//         }
//         else if (s == '+' && sflag == 0)
//         {
//             sflag = 1;
//         }
//         else if (s == '-' && sflag == 0)
//         {
//             sflag = 1;
//             z = -1;
//         }
//         else if (s >= 48 && s <= 57)
//         {
//             sflag = 1;
//             if (z < 0){
//                 if (res >= (INT_MIN + (s-48))/10){
//                     res = res * 10 - (s - 48);
//                 } else {
//                     return INT_MIN;
//                 }
//             } else {
//                 if (res <= (INT_MAX-(s-48))/10){
//                     res = res * 10 + (s - 48);
//                 } else {
//                     return INT_MAX;
//                 }
//             }
//         }
//         else
//         {
//             return res;
//         }
//     }
//     return res;
// }
int myAtoi(char *str)
{
    int res = 0, sflag = 0, pos = 1;
    for (int i = 0;; i++)
    {
        char s = str[i];
        // printf("[%c]", s);
        // 未到起始字符
        if (!sflag) {
            if (s == 32)
            {
                continue;
            }
            else if (s == '+')
            {
                sflag = 1;
                continue;
            }
            else if (s == '-')
            {
                sflag = 1;
                pos = -1;
                continue;
            }
        }
        
        // 计算当前字符值并加上res*10
        if (s >= 48 && s <= 57)
        {
            sflag = 1;
            if (pos < 0)
            {
                if (res >= (INT_MIN + (s - 48)) / 10)
                {
                    res = res * 10 - (s - 48);
                }
                else
                {
                    return INT_MIN;
                }
            }
            else
            {
                if (res <= (INT_MAX - (s - 48)) / 10)
                {
                    res = res * 10 + (s - 48);
                }
                else
                {
                    return INT_MAX;
                }
            }
        }
        else
        {
            return res;
        }
    }
    return res;
}


```