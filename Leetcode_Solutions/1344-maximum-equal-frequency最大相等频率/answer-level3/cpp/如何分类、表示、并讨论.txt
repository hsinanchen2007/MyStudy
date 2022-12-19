归类为数学，因为这道题让我想到的就是分类讨论，分析。
这里规定变量的含义：
设 cnt[i] : 数字i出现的次数
设 cnt_num[i] : 出现次数为i的数的个数, 也就是对 设i = cnt[j] 对cnt[j] 做统计, (cnt_num[cnt[j]]++ )
设 tot : 每个数出现次数的种类数, 也就是有多少个不同的cnt_num

然后，我们看一下，如果tot >= 3 那么我们无论怎么删数字，最多只能使tot >= 2， 
因此，如果一个前缀满足条件tot <= 2;
下面说合法的条件
如果当前缀长度为n
如果 1、tot == 1
合法的情况为 
    1-1、所有的数都只出现了一次 //如 1,2,3,4,5,6,7,8 //这样随便删哪个都一样
    1-2、只有一个数，出现了n次 //如 2,2,2,2,2,2,2 //这样随便删哪个都一样

如果2、tot == 2
n个数分为两个集合s1, s2;
s1中每个数都出现了 x1次 
s2中每个数都出现了 x2次
size(s1)表示s1中不同数的个数
不妨设x2 > x1
那么合法的情况为:
    2-1、size(s2) == 1 && x2 - x1 == 1 //如 2,2,2,3,3,4,4,5,5 //这样2在集合s2中，size(s2) = 1 并且x2 = 3, x1=2,只需要删一个2，即可满足条件
    2-2、size(s1) == 1 && x1 == 1 //如2,2,2,2,3,3,3,3,4,4,4,4,5 //这杨5在集合s1中，且x1 = 1, 删掉5即可满足条件

以上 四种情况可能会有重叠，但是没有关系，只需要保证完备，包含所有合法情况的判断即可
那么如何来写程序呢，
我们发现最多tot只有2，那么且需要知道x1和x2的大小关系，所以我们只用维护
最大的cnt[i] -> max_cnt 和 最小的cnt[i] -> min_cnt即可
就能满足我们需要的所有信息 //让我想到了充分统计量。。。
这样我们再用max_cnt和 min_cnt来表示一下刚才的各种情况

1-1、 tot==1 && max_cnt == 1
1-2、 tot==1 && min_cnt == n
2-1、 tot==2 && max_cnt-min_cnt == 1 && cnt_num[max_cnt] == 1
2-2、 tot==2 && min_cnt == 1 && cnt_num[min_cnt] == 1

```
class Solution {
public:
    int cnt[100007];
    int cnt_num[100007];
    int maxEqualFreq(vector<int>& nums) {
        memset(cnt, 0, sizeof(cnt));
        memset(cnt_num, 0, sizeof(cnt_num));
        int tot = 0, min_cnt = 1e7+7, max_cnt = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int now = nums[i];
            if (!cnt[now]) //if this number has never showed
            {
                cnt[now]++;
                if (!cnt_num[cnt[now]])
                {
                    tot++;
                }
                cnt_num[cnt[now]]++;
                min_cnt = cnt[now];
                max_cnt = max(max_cnt, cnt[now]);
            }
            else 
            {
                cnt_num[cnt[now]]--;
                if (!cnt_num[cnt[now]])
                {
                    tot--;
                    if (min_cnt == cnt[now])
                    {
                        min_cnt++;
                    }
                }
                cnt[now]++;
                if (!cnt_num[cnt[now]])
                {
                    tot++;
                }
                cnt_num[cnt[now]]++;
                max_cnt = max(max_cnt, cnt[now]);
            }
            //get ans
            //cout << i << "  " << tot << " " << min_cnt << " " << max_cnt << endl;
            if (tot == 1 && (min_cnt == i+1 || max_cnt == 1) ) 
            {
                ans = i+1;
                //cout << i << endl;
            }
            else if (tot == 2)
            {
                if (min_cnt == 1 && cnt_num[min_cnt] == 1) ans = i+1;// cout << i << endl;
                else if (max_cnt - min_cnt == 1 && cnt_num[max_cnt] == 1) ans = i+1;//cout << i << endl;
                
            }
        }
        return ans;
    }
};
```




