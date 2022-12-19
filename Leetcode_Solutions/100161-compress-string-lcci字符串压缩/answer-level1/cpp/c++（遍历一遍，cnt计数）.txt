```
class Solution {
public:
    string compressString(string S) {
        string res="";
        int cnt;
        for(int i=0;i<=S.size();i++){  //遍历到S[S.size()]时是'\0'结束符
            if(i==0) cnt=1;
            else if(S[i]==S[i-1]) cnt++;
            else{
                res+=S[i-1]+to_string(cnt);
                cnt=1;
            }
        }
        return res.size()<S.size()?res:S;
    }
};
```
- 思路：
  - 遍历一遍，cnt计数
- 时间复杂度：
  - o(n)
- 空间复杂度：
  - o(1)
- 结果:
  - 用时：86%（12ms）
  - 内存：100%

> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------