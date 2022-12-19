
比赛时没能解出来，后面调试了一会儿才调试出来，看来回溯法用的不熟啊。。。

#### 基本思路：

> 每个字母代表一个数,数**有范围**$[0,9]$，数**不重复**,设总的未知字母数为$m$,则$m$个数的可能形式的种类(10个元素排列的种类)为$p(10,m)$,基本想法是枚举排列的状态，最后判断是否合理。
>
> 上述的解题思路是回溯法。再生成排列后判断是否合理。
>
> ```cpp
> bool dfs(mask,re){    // 基本回溯
>     if(re的个数为m个) 判断是否满足条件
>     for(int i = 0;i<=9;i++){
>         if(当前元素已经使用) continue;
>         更新mask
>         更新re
>         dfs(mask,re)
>         回溯更新mask
>         回溯更新re
>     }
> }
> ```

明显，上面回溯法会超时。

#### 非程序的想法

> 一般是**先判断低位，再判断高位**。即,个位上的数不合理，十位上就不必比较。
>
> 例如:你生成的排列中个位数上的数分别为$T_0,T_0...,T_n$,与$S_0$,比如：
>
> ```
> words = ["SEND","MORE"], result = "MONEY"
> 假如你生成的排列使得words中的数为[1234,5672],result的数为56328
> 那么个位数上的数分别为[4,2],8，明显(4+2) != 8 不满足条件,不用判断十位上的数了。
> ```

#### 思考一：只判断个位数(最低位，0位)需要多少个未知数的值

> 设为$m_0$，遍历words与result的最低位即可得到$m_0$
>
> 既然判断个位需要$m_0$个未知数，那么表示如果生成的排列有$m_0$个数,例如：
>
> ```
> words = ["SEND","MORE"], result = "MONEY"
> 个位上[D,E,Y]3种元素，
> 假如你已经得到了一个3个元素的排列[4,2,8](同上面的例子对应)
> ```
>
> 如果这$m_0$个元素不满足个位数上的条件,即
>
> (4 + 2) != 8
>
> 表明以这$m_0$个元素的为前导的排列一定不满足条件，例如:
>
> $m_0$个元素为上面的[**4,2,8**],那么[**4,2,8**,0,...],[**4,2,8**,1,...]...这些排列一定不满足条件
>
> 即：
>
> 我:    喂，dfs（回溯函数）,你生成了多少个元素了?
>
> dfs:  生成了$m_0$个了。
>
> 我:    那你等会儿，我先去判断一下个位数上的条件是否满足，满足你就继续生成，不满足，那你得回溯了，不用继续生成了。

#### 思考二：判断十位（1位）上的数呢？

> 令十位、个位上的未知数个数总和为$m_1$,即：
>
> 我:    喂，dfs（回溯函数）,你生成了多少个元素了?
>
> dfs:  生成了$m_1$个了。
>
> 我:    那你等会儿，我先去判断一下十位上的数是否满足条件，满足你就继续生成，不满足，那你得回溯。

但是，判断十位（高位，1位）上的数时有可能有个位上的数（0位）的进位，所以判断十位的时侯，同时先求出个位（低位）的进位值，加上进位值后判断是否合理。

由以上分析可以得到:

1. 将低位上的未知数对应排列的前面
2. 当生成的排列的元素个数使得需要重新判断一个数位上的数是否满足条件时，

> 即生成了$m_0$个数时需要判断个位(0位)上的数是否满足条件，
>
> 同理,当生成了$m_1$个时需要判断十位(1位)上的数是否满足条件，
>
> ...

3. 最后就是判断生成完毕后是否满足条件

#### 思考三：需要哪些辅助？

1. 我如何知道当我生成了几个(上面讨论的$m_0,m_1,...$)元素的排列时需要重新判断一个当前最高位

```
        unordered_map<char,int> t;// 未知数的字母与排列的下标的映射
        // 即例如字母，[E,D,F,...]对应的值为[re[0],re[1],re[2],...](re为生成的排列)
        unordered_map<int,int> tt;
        int idx = 0;
        reverse(result.begin(),result.end());
        int n = result.size();
        for(auto &str:words){
            reverse(str.begin(),str.end());// 逆序，先处理低位，再处理高位
        }
        for(int i = 0;i<n;i++){
            if(t.find(result[i]) == t.end()) t[result[i]] = idx++;
            for(auto &str:words){
                int tn = str.size();
                if(i>=tn) continue;
                if(t.find(str[i]) == t.end()) t[str[i]] = idx++;
            }
            tt[idx] = i; // 此处回答上面问题
            // 即,有idx个未知数时，需要重新判断第i位
        }
```

2. 我需要知道一个未知字母对应生成的排列中的那个数(见上面代码)

3. 新的回溯算法如何写

```cpp
bool dfs(mask,re){  // 剪枝回溯
    if(re的元素个数为m_i个) 
        得到m_i个元素需要判断的最高位num
        判断是否满足条件 // m_i为上面的m_0,m_1,...
    for(int i = 0;i<=9;i++){
        if(当前元素已经使用) continue;
        更新mask
        更新re
        dfs(mask,re)
        回溯更新mask
        回溯更新re
    }
    return false;
}
```

#### 综上所述可以得到以下代码(CPP实现)

```cpp
class Solution {
public:
    // check最高位为num位（个位为0位，十位为1位...）
    int check(int num,vector<int> &re,vector<string> &words,string &result,unordered_map<char,int> &t){
        int add = 0;	// 进位值
        for(int i =0;i<=num;i++){
            int ts = re[t[result[i]]];
            int tts = add;
            for(auto &str:words){
                int tn = str.size();
                int x = 0;
                if(i<tn) x = re[t[str[i]]];
                tts += x;
            }
            add = tts/10;
            tts = tts%10;
            if(tts!=ts) return 0;
        }
        if((num+1)==result.size() && add == 0) return 2;	// 生成完成且条件满足
        return 1;	// 条件满足，但未生成完毕
    }
    bool dfs(int &mask,int &n,vector<int> &re,vector<string> &words,string &result,unordered_map<char,int> &t,unordered_map<int,int> & tt){
        if(tt.find(re.size()) != tt.end()){ // 一个新的高位产生

            int num = tt[re.size()];
            int tre = check(num,re,words,result,t);
            // 前num个数字的排列不合适，剪枝
            if(tre == 0) return false;
            // 前num个数的排列合适，而且已经生成了所有数
            if(tre == 2) return true;
        }
        for(int i = 0;i<10;i++){
            int tm = (1 << i);
            if(mask&tm) continue;
            re.push_back(i);
            mask += tm;
            if(dfs(mask,n,re,words,result,t,tt)) return true;
            mask-=tm;
            re.pop_back();
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char,int> t;
        unordered_map<int,int> tt;
        int idx = 0;
        reverse(result.begin(),result.end());
        int n = result.size();
        for(auto &str:words){
            reverse(str.begin(),str.end());
        }
        for(int i = 0;i<n;i++){
            if(t.find(result[i]) == t.end()) t[result[i]] = idx++;
            for(auto &str:words){
                int tn = str.size();
                if(i>=tn) continue;
                if(t.find(str[i]) == t.end()) t[str[i]] = idx++;
            }
            tt[idx] = i;
        }
        int mask = 0;
        vector<int> re;
        return dfs(mask,idx,re,words,result,t,tt);
    }
};
```

#### 总结

回溯法的基本写法可以先参考:

1. [39.组合总和](https://leetcode-cn.com/problems/combination-sum/)
2. [40.组合总和II](https://leetcode-cn.com/problems/combination-sum-ii/)
3. [46.全排列](https://leetcode-cn.com/problems/permutations/)

然后就是上面的剪枝思路了，自己写的还是挺麻烦的。。。