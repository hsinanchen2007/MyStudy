//注意是字符串S中有N个字母 但是输出的数组应该有N+1个 因为存放的是[0,1,...,N] 
//并且因为0到N是递增的数列 所以只需要遍历S 
//如果S[k]='I' 只需要把最小的值放到result[k]中即可
//如果S[k]='D' 将最大的放到result[k]
//采用双指针方法， i表示前面（小），j表示后面（大）
//当遍历完s中最后一个字母后，放的是result[N-1], result[N]就是最后剩下的i（或者写j都行）

```
class Solution {
public:
    vector<int> diStringMatch(string S) {
        //双指针
        //一个开始 一个结尾
        int N = S.size();
        vector<int> result(N+1); //注意[0,1,2...N] 一共是N+1个数 
        int i=0;
        int j=N;
        for(int k=0; k<N; k++){
            if(S[k]=='I'){
                result[k] = i;
                i++;
            }
            else{
                result[k]=j;
                j--;
            }
        }
        result[N] = j;
        return result;
    }
};

```
