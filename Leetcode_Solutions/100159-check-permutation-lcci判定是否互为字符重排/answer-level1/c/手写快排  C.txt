### 解题思路
此处撰写解题思路

### 代码

```c
void quicksort(char* s, int l ,int r)
{   
    int i = l;int j = r;
    char x;
    x =   s[(i+j)/ 2];

    while (i <= j)
    {

        while ( x < s[i]) i++;
        while ( x > s[j]) j--;
        if (i <= j)
        {
            char temp;
            temp = s[i];s[i] = s[j];s[j] = temp;
            i++;j--;
        } 
    }

    if (i < r) quicksort(s,i,r);
    if (l < j) quicksort(s,l,j);
}
bool CheckPermutation(char* s1, char* s2){
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    

    quicksort(s1, 0 , l1 - 1);
    quicksort(s2, 0 , l2 - 1);

    if (strcmp(s1,s2) == 0)
        return true;
    
    return false;

}
```