### 解题思路
此处撰写解题思路

### 代码

```c
/* 不懂 realloc会踩内存 */
// char * defangIPaddr(char * address){
//     int len = strlen(address);
//     realloc(address, len + 7);
//     int points = 3;
//     while (len >= 0) {
//         if (points == 0) {
//             break;
//         }
//         if (address[len] == '.') {
//             address[len + points * 2] = ']';
//             address[len + points * 2 - 1] = '.';
//             address[len + points * 2 - 2] = '[';
//             points--;
//         } else {
//             address[len + points * 2] = address[len];
//         }
//         len--;
//     }

//     return address;
// }
char * defangIPaddr(char * address) 
{
    char* result = (char*)malloc(strlen(address) + 7);
    int i = 0;
    int j = 0;
    while(address[i] != '\0') {
        if (address[i] == '.') {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
           i++;
        } else {
            result[j++] = address[i++];
        }
    }

    result[j] = '\0';

    return result;
}

```