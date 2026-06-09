# 方法1：直观做法
最直观的做法就是对所有区间和进行判断，然后计算次数，当然这个方法是不能够通过所有测试点的。以下的写法不是常规的写法，主要为了让大家更容易理解方法2。
```cpp
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int n= nums.size();
        int64_t presum = 0;
        vector<int64_t> S(n+1,0);
        int ret = 0;
        for(int i=1;i<=n;i++){
            //S[i] = S[i-1] + nums[i-1]
            presum += nums[i-1];
            for(int j=1;j<=i;j++){
                if(lower <= presum - S[j-1] && presum - S[j-1] <= upper) ret++;
            } 
            S[i] = presum;
        }
        return ret;
    }        
};

```

## 复杂度分析
* 时间复杂度：$O(n^2)$
* 空间复杂度：$O(n)$，$S$数组用来存储前缀和。

# 方法2：使用平衡树

## 算法
**方法1**中第二个for循环的作用是找出在$S[1]$到$S[i]$之间有多少个满足以下条件的$x$：
$$ lower \leq presum - x \leq upper,x\in S[0]...S[i-1] (1)$$


**方法1**中的$S$数组用来存储前缀和，但是这个数组并不是有序的，那么如果让这个数组变成有序的会有什么好处呢？我们将公式（1）变换一下得到:
$$ presum - upper \leq x \leq presum - lower,x\in S[0]...S[i-1]  (2)$$
那么如果`S`数组是有序的我们就可以通过两次二分查找计算出有多少个x满足条件（`d2-d1`）：
第一次二分查找找出第一个大于等于 `presum - upper `的位置`d1`；
第二次二分查找找出第一个大于 `presum - lower` 的位置`d2`。

接下来，我们需要为上述算法选择一个合适的数据结构：c++中我们使用STL中提供的`multiset`，这是一个支持重复元素的集合类，本质是一棵平衡树。

```cpp
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        int n= nums.size();
        int64_t presum = 0;
        multiset<int64_t> S;
        S.insert(0);
        int ret = 0;
        for(int i=0;i<n;i++){
            presum += nums[i];
            ret += distance(S.lower_bound(presum-upper),S.upper_bound(presum-lower));
            S.insert(presum);
        }
        return ret;
    }        
};

```
## 复杂度分析
* 时间复杂度：$O(nlog(n))$,单次插入操作以及二分查找操作时间复杂度为$O(logn)$,总时间复杂度为$O(nlog(n))$。
* 空间复杂度：$O(n)$，`multiset`中需要存储n+1个前缀和

# 方法三：权值线段树

## 算法
我们抽象一下**方法二**中平衡树的功能：
（1）add(x):插入数值，`add(presum) => S.insert(presum)`
（2）query(L,R)查询某个区间有多少个数,
`query(presum-upper,presum-lower) =>distance(S.lower_bound(presum-upper),S.upper_bound(presum-lower))`
我们会发现有一个更贴切的数据结构替换，那就是权值线段树。
但是对于这道题，使用线段树并不会带来方便，**在使用线段树之前需要对数据进行离散化操作，因为输入数据并不是连续并且有正有负**。离散化的数据任然保持原数据的大小关系，例如：
将[-2,5,-1]离散化成[2,3,1]后，第一位置仍然存储第二大的数值，第二个位置仍然存储最大的数值。

```cpp
#define LOWER_BOUND(S,PRESUM) (lower_bound(S.begin(),S.end(),(PRESUM)) - S.begin() + 1)
#define UPPER_BOUND(S,PRESUM) (upper_bound(S.begin(),S.end(),(PRESUM)) - S.begin())
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int n= nums.size();
        int ret = 0;
        vector<int64_t> S(n+1,0);
        for(int i=1;i<=n;i++)S[i] = S[i-1] + nums[i-1];
        
        sort(S.begin(),S.end());
        S.erase(unique(S.begin(),S.end()),S.end());

        int len = S.size();
        value = vector<int>(4*(len+1),0);
        int64_t presum = 0;
        add(LOWER_BOUND(S,presum),1,1,len);
        for(int i=0;i<n;i++){
            presum += nums[i];
            int64_t up = LOWER_BOUND(S,presum - upper);
            int64_t low = UPPER_BOUND(S,presum - lower);
            if(up <= low)
            ret +=  query(up,low,1,1,len) ;
            add(LOWER_BOUND(S,presum),1,1,len);
            
        }
        
        return ret;
    }        
    
private:
    vector<int> value;
    void add(int v,int o,int L,int R){
        if(L == R)value[o]++;
        else{
            int M = L + (R-L)/2;
            if(v <= M) add(v,o*2,L,M);
            else add(v,o*2+1,M+1,R);
            value[o] = value[2*o] + value[2*o + 1];
        }
    }
    int query(int ql,int qr,int o,int L,int R){
        if(ql <= L && R <= qr) return value[o];
        int ans = 0;
        int M = L + (R-L)/2;
        if(ql <= M) ans += query(ql,qr,2*o,L,M);
        if(M < qr) ans += query(ql,qr,2*o+1,M+1,R);
        return ans;
    }
    
        
};


```

## 复杂度分析
* 时间复杂度：$O(nlog(n))$,单次`query`,`add`以及离散化操作都是$O(log(n))$，因此总时间复杂度为$O(nlog(n))$。
* 空间复杂度：$O(n)$，线段树理论上需要2*n大小的数组，但是实际为了防止溢出，需要 $4*n$的大小，由于需要离散化还需要存储前缀和。复杂度为O(n)。

# 方法4 归并排序
回到根本，这道题是让我们求解任意$S[i] - S[j]$满足：
$$ lower \leq S[i] -S[j] \leq upper，j \leq i$$
如果存在下面这个序列，左边蓝色部分是有序的，右边黄色部分是有序的，求有多少个答案满足：
 $$0 \leq S[i] -S[j] \leq 4 ,S[i]\in黄色，S[j]\in 蓝色$$
![blob](https://pic.leetcode-cn.com/18adf327ab43632a03e2fb8095a029b4d54fa52e1a106ccb9cb97a22e734076a-file_1571325628046)
我们尝试求解:
首先Left指针指向蓝色部分最左端，Lower指针和Upper指针指向黄色部分最左端。
![blob](https://pic.leetcode-cn.com/768d122f4290de25219a2fc83167160afd05355f0bfc1552e0b1dfd3257f4012-file_1571325628054)

当S[Lower] - S[Left] < 0就继续移动Lower；当S[Upper] - S[Left] <= 4就继续移动Upper之后可以得到：
![blob](https://pic.leetcode-cn.com/bf057af098100994d5c7038b37fed4f77a4312337c741b6e2e979e4e1bc8eea2-file_1571325628056)
此时Upper - Lower就是Left（-1）所对应的个数，这里等于0，因为Upper和Lower之后的值更大，更不可能满足要求。
接着向左移动Left，但是Upper和Lower并不需要往后移动。
![blob](https://pic.leetcode-cn.com/b820cb2a4b73c51a571576bbaea1ab0317254165d4f3d8fb7221dccdee021b2b-file_1571325628061)
因此Left（0）对应个数为0，继续移动Left,并相应地移动Upper和Lower得到：
![blob](https://pic.leetcode-cn.com/1208145e7d81d3eed73b8b696e747594b581b615081ca4b4df05f2ae8129b51a-file_1571325628064)
可以得到Left(7)对应个数为2,最后移动Left，Upper和Lower得到：
![blob](https://pic.leetcode-cn.com/d2fa090315e478dd2a590c9b19a1c3286471e98908dc2f0a641f626045d58512-file_1571325628067)
可以得到Left(9)对应个数为0。
因此最后答案为2，并且我们通过线性的实现就完成了求解过程，因为Left,Upper,Lower都只向右扫描了一遍。

我们回顾一下归并排序，归并排序能够将两个有序序列在线性时间复杂度下完成合并，我们这里是类似的。
```cpp
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<int64_t> S(n+1,0);
        vector<int64_t> assist(n+1,0);
        for(int i=1;i<=n;i++)S[i] = S[i-1] + nums[i-1];
        
        return merge(S,assist,0,n,lower,upper);
        
    }
    int merge(vector<int64_t> &S,vector<int64_t> &assist,int L,int R,int low,int up){
        
        if(L >= R) return 0;
    
        int cnt = 0;
        int M = L + (R-L)/2;
        cnt += merge(S,assist,L,M,low,up);
        cnt += merge(S,assist,M+1,R,low,up);
        int Left = L;
        int Upper = M+1,Lower = M+1;
        while(Left <= M){
            while(Lower <= R && S[Lower] - S[Left] < low)Lower++;
            while(Upper <= R && S[Upper] - S[Left] <= up)Upper++;

            cnt += Upper - Lower;
            Left++;
        }
        //以下为归并排序中归并过程
        Left = L;
        int Right = M + 1;
        int pos = L;
        while(Left<= M || Right <= R){
            if(Left > M)assist[pos] = S[Right++];
            if(Right > R && Left <= M)assist[pos] = S[Left++];
            
            if(Left <= M && Right <= R){
                if(S[Left] <= S[Right])assist[pos] = S[Left++];
                else assist[pos] = S[Right++];
            }
            pos++;     
        }
        for(int i=L;i<=R;i++)S[i] = assist[i];
        return cnt;
    }
};
```

## 复杂度分析
* 时间复杂度：$O(nlog(n))$，分治算法，每次合并过程为线性复杂度，因此总复杂度为$O(nlog(n))$。
* 空间复杂度：$O(n)$，归并过程需要等长的辅助数组。

