直接暴力。。。花里胡哨duck不必。。。。
```
vector<int> distributeCandies(int candies, int num_people)
{
    vector<int> rec(num_people, 0);
    int cur = 1, k = 0;
    while(candies >= cur)
    {
        rec[k] += cur;
        candies -= cur;
        cur++;
        k = (k + 1) % num_people;
    }
    if(candies != 0)
        rec[k] += candies;
    return rec;
}
```
