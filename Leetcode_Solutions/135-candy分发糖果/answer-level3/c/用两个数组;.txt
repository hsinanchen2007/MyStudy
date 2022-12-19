![image.png](https://pic.leetcode-cn.com/005c826b68bbd824c354b12058f134ca24563e4b79a5c84fdf56c89fabe69da0-image.png)


int Bullet(int* ratings, int ratingsSize)
{
    int i,val;
    int * p = (int*)malloc(ratingsSize*sizeof(int));
    int * p1 = (int*)malloc(ratingsSize*sizeof(int));
    for (i =0; i < ratingsSize; i++)
    {
        *(p+i) = 0x01;
        *(p1+i) = 0x01;
    }

    for (i = 1; i < ratingsSize; i++)
    {
        if (ratings[i] > ratings[i-1])
        {
            p[i] = p[i-1] + 1;
        }
    }
    for (i = ratingsSize-2; i >=0; i--)
    {
        if (ratings[i] > ratings[i+1])
        {
            p1[i] = p1[i+1] + 1;
        }
    }


    val = 0;
    for (i = 0; i < ratingsSize; i++)
    {
        val += p[i] > p1[i] ? p[i] : p1[i];
    }
    free(p);
    free(p1);
    return val;
}