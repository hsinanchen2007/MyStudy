#### 题目：
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.
***
#### 错误解法：动态规划
题目可以表述为从m+n个数中选k个数使组合数最大。很容易联想到01背包问题，以k的“背包容量”从数列中选数，使得组合成的数最大。  
但实际上这个问题不具备最优子结构，和01背包问题的价值累加最大不同，01背包问题中使得前k个物品价值最大的方案，一定也使得前k-1个物品价值最大，而在保持数字原顺序组成最大数的这个标准上，小规模的问题的最优解不能作为大规模问题最优解的基础，因此这题不能用动态规划（仅个人认为，欢迎大神来讨论一下）。

以下是我踩过的坑，不能ac。  

```nums1``` 长度```len1```，```nums2```长度```len2```，```len=len1+len2```  
用一个结构体来表示选数方案：
```cpp
struct selection{
        vector<int> n1, n2;
    };
```
- 选择状态  
```selection dp[i][x],0<=i<=len,0<=x<=k``` 表示从```nums```的前i个数(0~i-1)中取x个数的方案，使这x个数按规则```create()```生成的数最大。
- 状态转移方程  
    - 如果选nums[i-1]，临时方案temp1
        - 0<=i-1<len1  
        临时方案为:  
        ```temp1 = dp[i-1][x-1]```  
        ```temp1.n1.emplace_back(nums[i-1])```
        - len1<=i<len
        临时方案为:  
        ```temp1 = dp[i-1][x-1]```  
        ```temp1.n2.emplace_back(nums[i-1])```
    - 如果不选nums[i]，临时方案temp2  
    ```temp2 = dp[i-1][x]```

```dp[i][x] = judge(temp1, temp2) ? temp1 : temp2;```
- 边界  
保证```i,x>=1```，需要初始化第0行，第0列为空方案  
- 处理顺序  
涉及左上方、上方，处理顺序为从上到下，从左到右。
```cpp
class Solution {
public:
    struct selection{
        vector<int> n1, n2;
    };

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1=nums1.size(), len2=nums2.size(), len=len1+len2;
        vector<int> ans;
        if(len==0) return ans;
        selection dp[len+1][k+1];
        //填表
        for(int i=1; i<=len; i++){
            for(int x=1; x<=k; x++){
                //若选nums[i-1]
                selection temp1 = dp[i-1][x-1];
                if(i-1<len1) temp1.n1.emplace_back(nums1[i-1]);
                else temp1.n2.emplace_back(nums2[i-1-len1]);
                //若不选nums[i-1]
                selection temp2 = dp[i-1][x];
                //判断temp1和temp2谁大
                dp[i][x] = judge(temp1, temp2) ? temp1 : temp2;
            }
        }
        create(dp[len][k], ans);
        return ans;
    }

    bool judge(selection &a, selection &b){
        //判断a是否比b更好
        vector<int> an, bn;
        create(a, an);
        create(b, bn);
        int sa=an.size(), sb=bn.size();
        if(sa>sb) return true;
        else if(sa<sb) return false;
        else{
            for(int i=0; i<sa; i++){
                if(an[i]>bn[i]) return true;
                else if(an[i]<bn[i]) return false;
            }
            return false;
        }
    }

    void create(selection &a, vector<int> &an){
        int t1=a.n1.size(), t2=a.n2.size(), p1=0, p2=0;
        while(p1<t1 && p2<t2){
            bool out = true;
            int i;
            for(i=0; p1+i<t1 && p2+i<t2; i++){
                if(a.n1[p1+i]!=a.n2[p2+i]){
                    if(a.n1[p1+i]>a.n2[p2+i]) an.emplace_back(a.n1[p1++]);
                    else an.emplace_back(a.n2[p2++]);
                    out = false;
                    break;
                }
            }
            if(out){
                if(p1+i>=t1) an.emplace_back(a.n2[p2++]);
                else an.emplace_back(a.n1[p1++]);
            }
        }
        while(p1<t1) an.emplace_back(a.n1[p1++]);
        while(p2<t2) an.emplace_back(a.n2[p2++]);
        return;
    }
};
```
#### 正确解法：选数是有策略的
组成最大数的方案，其各自在nums1和nums2中也一定是同等条件下的最大数。  
列举nums1，2各取几个数。  
ac代码：
```cpp
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1=nums1.size(), len2=nums2.size();
        vector<int> ans;
        for(int n1=0; n1<=min(len1, k); n1++){
            int n2 = k - n1;
            if(n2>len2) continue;
            vector<int> se1, se2, res;
            getNumbers(nums1, se1, n1);
            getNumbers(nums2, se2, n2);
            create(se1, se2, res);
            if(judge(res, ans)) ans = res;
        }
        return ans;
    }

    void getNumbers(vector<int>& nums, vector<int>& se, int k){
        vector<int>::iterator s = nums.begin();
        vector<int>::iterator e = nums.end() - k + 1;
        while(k--){
            vector<int>::iterator it = max_element(s, e);
            se.emplace_back(*it);
            s = it + 1;
            e++;
        }
        return;
    }

    void create(vector<int>& a, vector<int>& b, vector<int>& res){
        int t1=a.size(), t2=b.size(), p1=0, p2=0;
        while(p1<t1 && p2<t2){
            bool out = true;
            int i;
            for(i=0; p1+i<t1 && p2+i<t2; i++){
                if(a[p1+i]!=b[p2+i]){
                    if(a[p1+i]>b[p2+i]) res.emplace_back(a[p1++]);
                    else res.emplace_back(b[p2++]);
                    out = false;
                    break;
                }
            }
            if(out){
                if(p1+i>=t1) res.emplace_back(b[p2++]);
                else res.emplace_back(a[p1++]);
            }
        }
        while(p1<t1) res.emplace_back(a[p1++]);
        while(p2<t2) res.emplace_back(b[p2++]);
        return;
    }

    bool judge(vector<int>& a, vector<int>& b){
        int sa=a.size(), sb=b.size();
        if(sa>sb) return true;
        else if(sa<sb) return false;
        else{
            for(int i=0; i<sa; i++){
                if(a[i]>b[i]) return true;
                else if(a[i]<b[i]) return false;
            }
            return false;
        }
    }
};
```