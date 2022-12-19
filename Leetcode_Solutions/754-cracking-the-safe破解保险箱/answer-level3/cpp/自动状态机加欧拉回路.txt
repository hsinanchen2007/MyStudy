### 解题思路
此处撰写解题思路
首先这道题要求输出长度最短的总字符串，很显然，总字符串长度最短为n^k+n-1,这时的输出字符串中，相邻的n个字符组成的子串均不相同。
那么对于任意的n和k，是否能找出一个这样的长为n^k+n-1的字符串呢？答案是肯定的。下面的证明使用有限状态机结合欧拉图的相关定理。
先不给定前n-1个字符，任意选取k中n-1个字符组成输出串的前端，将当前输出串的最后n-1个字符看成一个k进制数字，为当前字符串的状态。
则可知，若将状态机的状态视为节点，转移看作有向图的边，则该状态机转换为含有n^k个节点和n^k条边的有向图。易得该图为连通图，且每个节点有k条出边，k条入边，为一个有向欧拉图，从任意节点出发，均可以在不重复通过任何边的情况下，就一次性走完所有边。
回到状态机的情况，每一条边代表在输出字符串中有一个长为n的子串，且状态图中每条边代表的子串均不相同，所有边即为所有长度为n的串。所以在对应的图中的一笔画，就是一个满足条件的输出串。同时对于状态图中除初始状态的任意状态，若我们到达了该状态，则必定有一条边能转移到其他状态。我们需要保证的就是，在走回到出发状态的最后一条入边时，已经走完了其他所有边。
在代码中，将n-1个0设为初始状态，在进行转移时，优先考虑大于0的转移，这样就可以保证最后一个转移到的状态为n-1个0。



### 代码

```cpp
class Solution {
public:
    bool all_save[4096];
    char out_str[5000];
    int predel(int n,int k)
    {
        int max=k;
        for(int i=1;i<n;i++)
        {
            max=max*k;
        }
        for(int i=0;i<max;i++)
        {
            all_save[i]=false;
        }
        for(int i=0;i<(n-1);i++)
        {
            out_str[i]='0';
        }
        out_str[max+n-1]='\0';
        return max;
    }
    string crackSafe(int n, int k) {
        int max=predel(n,k);
        int base=0,shift=max/k;
        int temp;
        //all_save[0]=true;
        for(int i=n-1;i<(max+n-1);i++)
        {
            for(int j=k-1;j>=0;j--)
            {
                temp=base*k+j;
                if(all_save[temp]==false)
                {
                    all_save[temp]=true;
                    base=temp%shift;
                    out_str[i]=j+'0';
                    break;
                }
                //cout<<"error\n"<<endl;
            }
        }
        //out_str[max+n-2]='0';
        string output(out_str);
        return output;
    }
};
```