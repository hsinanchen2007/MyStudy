```c
/**
 * @brief 
 * 使用额外的内存空间保存数据, 空间复杂度O(n)
 * @param s 
 * @param sSize 
 */
void reverseString1(char* s, int sSize) {
    char *n = (char *)malloc(sizeof(char)*sSize);
    for(size_t i = sSize; i > 0; i--)
    {
        n[sSize-i] = s[i-1];
    }
  
    memcpy(s, n , sSize);
    free(n);
}

/**
 * @brief 
 * 双指针，原地翻转
 * @param s 
 * @param sSize 
 */
void reverseString2(char* s, int sSize) {
    int i = 0;
    int j = sSize-1;
    int tmp;
    while(i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

void swap(int start, int end, char *s)
{
    if(start >= end)
        return;
    
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    swap(start+1, end-1, s);
}
/**
 * @brief 递归的交换首尾字符
 * 
 * @param s 
 * @param sSize 
 */
void reverseString3(char *s, int sSize)
{
    int len = sSize-1;
    swap(0, len, s);
}
```