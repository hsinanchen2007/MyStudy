### 解题思路
此处撰写解题思路

### 代码

```c
bool checkInclusion(char * s1, char * s2){
    int index[128] = {0};
    int index2[128] = {0};
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    unsigned long long sum1 = 0;
    unsigned long long sum2 = 0;

    int j = 0;
    
    char tmp[8] = {0};
    tmp[0] = s1[0];

    char *p = NULL;
    char *h = NULL;  
    char *t = NULL; 

    if (len1 > len2)
        return false;

    if (len1 == 1) {
        if (strstr(s2, s1) != NULL)
            return true;
        else
            return false;
    }
    
    for (int i = 0; i < len1; i++) {
        index[*(s1 + i)]++;
        sum1 = sum1 + s1[i]; 
    }
     printf("sum1: %u\n", sum1);
    

    t = s2;
    while (1) {
        //memcpy(index2, index, 4 * 128);
        p = strstr(t, tmp);
        //printf("p: %s\n", p);
        if (p == NULL)
            break;

        if (p - s2 <= len1 - 1 ) {
            h = s2;
           // printf("h0: %s\n", h);
        } else {
            h = p - len1 + 1; 
            //printf("h1: %s\n", h);
        }

        int len = 0;
        if (p - h < s2 + len2 -1 - p)
            len = p - h;
        else 
            len = s2 + len2 -1 - p;
        
        if (len1 == len2)
            len = 0;

        for (int i = 0; i <= len; i++) {    
 #if 1      
            sum2 = 0;
            for (j = 0; j < len1; j++) {
                sum2 = sum2 + h[j];
            }
            //printf("sum2: %u\n", sum2);
            if (sum1 != sum2) {
                h++;
                continue;    
            }
#endif
            memcpy(index2, index, 4 * 128);
            for (j = 0; j < len1; j++) {
                if (index2[*( h + j)] > 0)
                    index2[*( h + j)]--;
                else
                    break;
            }

            if (j == len1)
                return true;
            
            h++;
        }

        if ((p + 1) < s2 + len2)
            t = p + 1;
        else
            break;
    }
    return false;
}
```