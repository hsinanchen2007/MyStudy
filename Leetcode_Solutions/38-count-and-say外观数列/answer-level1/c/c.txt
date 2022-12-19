### 解题思路
此处撰写解题思路
1、c使用指针时，必须要malloc空间，才能使用；
2、字符串结尾是'\0'；
3、strcpy进行字符串拷贝；

### 代码

```c
char * countAndSay(int n){
    char *arr = (char *)malloc(sizeof(char) * 5000);
    char *tmp = (char *)malloc(sizeof(char) * 5000);
    int count = 1;
    int i = 0, num_arr = 0, num_tmp = 0;

    arr[0] = '1';
    arr[1] = '\0';

    for (i = 1; i < n; i++)
    {
        //每个字符串初始化
        num_arr = 0;
        num_tmp = 0;
        count = 1;

        while(arr[num_arr] != '\0')
        {
            if(arr[num_arr] == arr[num_arr + 1])
            {
                count++;
            }
            else
            {               
                tmp[num_tmp++] = count + '0';
                tmp[num_tmp++] = arr[num_arr];

                count = 1;
            }

            num_arr++;
        }

        tmp[num_tmp] = '\0';
        strcpy(arr, tmp);
    }

    return arr;
}
```