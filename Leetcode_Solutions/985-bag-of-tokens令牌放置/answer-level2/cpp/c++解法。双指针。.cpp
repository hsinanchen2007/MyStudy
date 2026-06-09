推荐使用双指针解答
主要思路：为得到尽可能大的分数score，应该贪婪的得到最多的能量P,每一步到达最优解。先将数组进行排序，用需要能量少的换取分数，用分数换取拥有能量多的。当能量P>=当前令牌需要的能量tokens[i]，则分数score++,指针i右移，而当能量P<当前令牌需要的能量token[i],使用分数换取能量多的tokens[j],则分数score--,指针i右移、指针j左移，当i=j时break。
```
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int score=0,total=0;
        int i=0,j=tokens.size()-1;
        if(tokens.size()==0)
            return 0;
        sort(tokens.begin(),tokens.end());
        if(P<tokens[0])
            return 0;
        for(int i=0;i<tokens.size();i++)
            total+=tokens[i];
        if(P>total)
            return tokens.size();
        while(i<=j){
            if(P>=tokens[i]){                                //能量P>=tokens[i]
                score++;                                     //能量少的换取分数
                P-=tokens[i];
                i++;
            }
            else{                                            //能量P<tokens[i]
                if(P+tokens[j]>tokens[i]&&score>0){          //分数换取能量多的
                    if(j==i)
                        break;
                    score--;
                    P+=tokens[j];
                    j--;
                }
            }
        }
        return score;
    }
};
```
