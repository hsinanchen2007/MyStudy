用小的能量换分数，得到了分数获取大的能量。用大的能量可以换更多的分数

```C++
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int max_score = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int left = 0;
        if (tokens.size() == 0) {
            return 0;
        }
        int right = tokens.size() - 1;
        if (right < 1) {
            if (tokens[0] < P) {
                max_score = 1;
            }
            return max_score;
        }
        while(left <= right) {
            if (tokens[left] <= P) {
                score += 1;
                P -= tokens[left];
                max_score = max_score > score ? max_score : score;
                left++;
            }else{
                if (score >= 1) {
                    P += tokens[right];
                    score -= 1;
                    right--;
                }else{
                    return max_score;
                }
            }   
        }     
        return max_score;
    }
};
```
