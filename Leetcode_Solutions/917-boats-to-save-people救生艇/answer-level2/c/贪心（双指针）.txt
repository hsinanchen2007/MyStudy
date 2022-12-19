### 解题思路
最开始没看见只能装俩人。。。
1. 排序是肯定要的
2. 贪心思想，先把胖子搞一起，因为胖子能在瘦子肯定也能所以尽量让胖的在一艘船，实在不行再放瘦的

### 代码

```c
int comp(int *a,int *b){
    return *a-*b;
}
int numRescueBoats(int* people, int peopleSize, int limit){
    qsort(people,peopleSize,sizeof(int),comp);
    int count=0;
    for (int l=0,r=peopleSize-1;r>=l;){
        int sum=0,flag=0;
        while(r>=l && flag<2 && sum+people[r]<=limit){
            sum += people[r--];
            flag++;
        }
        while(r>=l && flag<2 && sum+people[l]<=limit){
            sum += people[l++];
            flag++;
        }
        count++;
    }
    return count;
}
```