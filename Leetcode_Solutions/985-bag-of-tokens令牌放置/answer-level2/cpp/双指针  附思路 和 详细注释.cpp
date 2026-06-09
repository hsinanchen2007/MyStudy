/*
思路：首先考虑出现的几种情况
    1.空 tokens  ====》 return 0
    2.P太小了，连最小的tokens都不能兑换成分数 ==》 return 0
    3.如果不是1，2两种情况，那么至少可以兑换成 1分，有了这1分，就可以拿去买最大的tokens来获得最大的power，然后那这个power来买小的token兑换成分数（赚差价），这样 power就是不减，即会增加，最差也不会减少。  拿分买token的条件条件是：P不够买任何一个tokens了，那么为了不亏本，原有的P + 要换的tokens（最大的tokens）  >=  最小的tokens， 保证拿分换power以后还能换会分，因为最后是要分最大，否则没必要换成power
    
发现，最大或最小的两个tokens，所以可以排序以后，使用双指针指向首尾，通过指针向中间移动来代替 去掉已使用的tokens 这个操作

首尾指针相遇====》遍历完了  ===》因为是 pBegin == pEnd的时候退出，所以还要判断这个位置的tokens能不能换成分

*/

```


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (tokens.size() == 0) //空 tokens
           return 0;
        
        sort(tokens.begin(), tokens.end());//排序
        int course = 0;  // 计数器
        vector<int>::iterator pBegin, pEnd;//双指针（迭代器）
     
        pBegin = tokens.begin();
        pEnd = tokens.end()-1;
        if (P < *pBegin)// 如果 P都不够买最小的一个 那就啥都买不了
            return 0;
        while (pBegin < pEnd){//这里P至少可以买最小的*pBegin
            if (P < *pBegin){//第一次不会是在这
                if (P + *pEnd > *pBegin){
                    //不亏（分数不减），就买了（实际上power也是不减,或者说大多数都是加的情况）
                    //这里不亏是： 用已经有的 1分，买最大的tokens活得power，这个power足够买一个最小的tokens（*pBegin），所以分数不减，power不减
                    P += *pEnd; //因为 *pEnd >= *pBegin
                    P -= *pBegin;
                    pEnd --;
                    pBegin ++;
                }
                else
                    return course;
            }
            else{//P有余 可以直接购买  包括了第一次的情况，即在此获得了1积分
                //这里是盈利的地方了
                //上一部分，power不减，就会有余，那么就可以换分
                P -= *pBegin;
                course ++;
                pBegin ++;
            }
        }
        if (P >= *pBegin)//最后，因为是pBegin == pEnd的时候退出循环
            course ++; //最后一个可能还能换分的
       
        return course;
    }
};
```
