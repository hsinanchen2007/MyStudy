### 解题思路
如果将所有数按大小排列的顺序存入一个数组，得到一个直方图，那么每个数需要加的次数就
        由它的最小区间长度(连续区间,它在其中是最小值)以及它在区间的位置决定
        这个需要加的次数推导如下:
            如果i元素在一个长度为n的区间处于第k个位置,那么按题意
            如下这些子区间使得它在其中是最小值
                以自身开始:(ak),(ak,ak+1)...,(ak,...,an)
                以前一个数开始:(ak-1,ak),(ak-1,ak,ak+1)...,(ak,...,an)
                ...
                (ai-k,...,ak)  ...  (ai-k,...,ak,...,an)
                其实它左边每一个数提供的区间数与它自身提供的数目一致,因为要把它包含在内
        所以i元素所要添加的次数就是(i在区间中的位置+1  表示i左边元素的个数以及它自身)*(n-i,即以i前面的数为起始能提供的区间数)

### 代码

```cpp
class Solution {
public:


    //实现稳定快排 去重(重复数会重复计算最小区间区域)
    static bool cmp2(pair<int,int> &p1,pair<int,int> &p2){
        if(p1.first == p2.first)
            return p1.second<p2.second;
        return p1.first<p2.first;
    }
    //计算长度为n的区间最小元素位于位置i时它需要被加的次数
    int cal(int n,int i){
        return (i+1)*(n-i);
    }
    int sumSubarrayMins(vector<int>& A) {
        int M = pow(10,9)+7;//^表示异或
        int N = A.size();
        vector<pair<int,int>>V(N);
        for(int i=0;i<N;i++){
            V[i] = pair<int,int>(A[i],i);
        }
        sort(V.begin(),V.end(),cmp2);
        //获取每个元素的排序编号
        vector<int>  T(N);//T[i]表示第i个数按大小排序后的序号,保证T[i]内无重复数
        for(int i=0;i<N;i++){
            T[V[i].second] = i;
        }
        int ans = 0;
        int l,r;//如果我们知道了i号数的最小区间区域,那么i+1的l就可以确定了,如果它比i大那么l=自己,否则=li
        for(int i=0;i<N;i++){
            //查找位置i的最小区间长度(它在这区间内是最小)
            if(i==0){
                l=-1;r=1;
            }else{
                if(T[i]>T[i-1]){
					l=i-1;
                }
				r=i+1;
            }
            //向左向右找区间边界
			while(l>=0 and T[l]>T[i]) l--;
            //i在这个(l,r)区间内是最小值
            while(r<N and T[r]>T[i]) r++;//该栈出场了
            int repeat_times = cal(r-l-1,i-l-1);//第i个数的重复次数
            ans = (ans+(repeat_times*A[i])%M)%M;
        }
        return ans;
    }
};
```