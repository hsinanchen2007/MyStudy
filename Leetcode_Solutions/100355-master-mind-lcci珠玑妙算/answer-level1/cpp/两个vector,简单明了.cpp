### 解题思路
第一步：分别存储颜色的出现次数，相等则为猜中；
第二步：取最小的次数，相加就是猜中和伪猜中的和；
第三步：和减第一步的猜中则为伪猜中；

### 代码

```cpp
class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        //索引0，1，2，3分别为红色、黄色、绿色、蓝色
        vector<int> solutionColor(4,0);
        vector<int> guessColor(4,0);
int guessRight=0;
int count=0;
        for(int i=0;i<solution.size();i++)
        {
            if(solution[i]==guess[i])
                guessRight++;

            if(solution[i]=='R')
            solutionColor[0]++;
            else if(solution[i]=='Y')
            solutionColor[1]++;
            else if(solution[i]=='G')
            solutionColor[2]++;
            else if(solution[i]=='B')
            solutionColor[3]++;

            if(guess[i]=='R')
            guessColor[0]++;
            else if(guess[i]=='Y')
            guessColor[1]++;
            else if(guess[i]=='G')
            guessColor[2]++;
            else if(guess[i]=='B')
            guessColor[3]++;
        }
        for(int i=0;i<4;i++)
        {
            count=count+min(solutionColor[i],guessColor[i]);
        }
        return {guessRight,count-guessRight};
    }
};
```