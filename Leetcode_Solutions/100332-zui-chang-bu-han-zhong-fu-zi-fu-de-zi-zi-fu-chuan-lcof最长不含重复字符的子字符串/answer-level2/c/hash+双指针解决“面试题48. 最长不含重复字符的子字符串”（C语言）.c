### 解题思路
典型的双指针问题，这里给出C语言的解法。

使用哈希表记录重复元素出现和消失的位置。

先移动右指针到第一次出现重复的位置，记录最值；

再移动左指针将重复消除。

注意最后一次的处理。

![image.png](https://pic.leetcode-cn.com/ae5fa832c5f805098f73265cde30df76d89b635e74f4fcae1be95fdd40039e18-image.png)


### 代码

```c
#define MMAX(a, b)      ((a) > (b)? (a) : (b))

//【算法思路】hash+双指针。hash记录个数，重复即判断是否有2.先移动右指针，到重复为止，再移动左指针到不重复为止。
//      注意字符为大小写
int lengthOfLongestSubstring(char* s){
    if(s == NULL || strlen(s) == 0)
    {
        return 0;
    }

    int slen = strlen(s);

    int hash[128] = {0};

    int dup_cnt = 0;

    int ll = 0, rr = 0;
    int ret = 0;
    while(rr < slen)
    {
        //printf("---->ll = %d, rr = %d, dup_cnt = %d\n", ll, rr, dup_cnt);
        hash[s[rr]]++;

        dup_cnt += hash[s[rr]] == 2? 1 : 0;
        if(dup_cnt == 0)
        {
            rr++;
            continue;
        }

        //此时是第一次重复
        int tmax = rr - ll;
        ret = MMAX(ret, tmax);

        //调整左指针
        for(int i = ll; i < rr; i++)
        {
            hash[s[i]]--;
            
            dup_cnt -= hash[s[i]] == 1 ? 1 : 0;
            if(dup_cnt == 0)
            {
                ll = i + 1;
                break;
            }
        }

        rr++;
    }

    //处理最后一次
    int tmax = rr - ll;
    ret = MMAX(ret, tmax);

    return ret;
}
```