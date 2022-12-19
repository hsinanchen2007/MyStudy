思路：
1.从小到大排序
2.优先从左到右向上翻token得分，直到没有能量
3.没能量后，如果score大于0分，而且剩余能量加上能通过卖分得到的最大能量 还能再向上翻token就卖一分


    int Campare(const void *p1, const void *p2)
    {
        return *((int *)p1) - *((int *)p2);
    }

    int bagOfTokensScore(int* tokens, int tokensSize, int P){
        int score = 0;
        int minIdx = 0;
        int maxIdx = tokensSize - 1;
        int curP = P;

        qsort(tokens, tokensSize, sizeof(int), Campare);

        while (minIdx <= maxIdx) {
            if (curP >= tokens[minIdx]) {
                score++;
                curP -= tokens[minIdx];
                minIdx++;
                continue;
            }

            if (score > 0 && maxIdx > minIdx && tokens[maxIdx] + curP >= tokens[minIdx]) {
                score--;
                curP += tokens[maxIdx];
                maxIdx--;
                continue;
            }
            
            break;
        }

        return score;
    }

