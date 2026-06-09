通过一个表来记录信任次数，最后通过判定N-1,和本身是否信任过他人(法官是不信任他人的)来确认
```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> believeMap(N,0);

        for(int i = 0;i < trust.size();i++)
        {
            //int flag = trust[i][0];//人的标记号
            int flagBel = trust[i][1];//某个标记好信任人的标记
            believeMap[flagBel - 1]++;
            
        }
        for(int i = 0;i < N;i++)
        {
            if(believeMap[i] == N - 1)//除自己其他人都信任的条件
            {
                bool isRight = true;
                for(int k = 0;k < trust.size();k++)
                {
                    if(trust[k][0] - 1 == i)
                    {
                        isRight = false;
                        break;
                    }
                }
                if(isRight)
                    return i + 1;
            }
        }
        return -1;
    }
};
```
