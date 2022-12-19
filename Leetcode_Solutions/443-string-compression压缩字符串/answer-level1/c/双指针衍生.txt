### 解题思路
三个指针，slow指向子串的头，fast遍历子串，进行计数，arrRes记录新的字符串


### 代码

```c
int compress(char* chars, int charsSize){
    
    int i = 0;
    int fast , slow = 0;
    int arrRes = 0;
    char tmp [5];
    int count;

    
    for (fast = 0, slow = 0; fast < charsSize; slow = fast)
    {
        count = 0;
        
        while (fast < charsSize && chars[fast] == chars[slow])
        {
            fast ++;
        }
        
        chars[arrRes] = chars[slow];
        
        count = fast - slow;
        if (count == 1) //一个字母不用压缩
        {
            arrRes ++;
            continue;
        }
        
        sprintf(tmp, "%d", count);
        //printf("%d\n", strlen(tmp));
        for (i = 0; i < (int)strlen(tmp); i ++)
        {
            arrRes ++;
            chars[arrRes] = tmp[i];
        }
        arrRes ++;
    }
    
    
    return arrRes;
}


```