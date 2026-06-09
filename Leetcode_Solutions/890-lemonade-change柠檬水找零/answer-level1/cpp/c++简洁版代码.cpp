原先是用if语句将每个情况罗列出来，
20-> （10->5)|| (10 -> !5) || （5*3）|| (5的个数小于三)
10 -> 5 || 10 -> !5
5
在所对应的不符合情景的情况返回false，但是在借鉴国际站里面的代码以后， 我发现可以一开始假设符合调件并且将对应的十块与五块对应增加和减少，然后最后加一个判定条件表示如果5快的数目小于0 ， 则返回false，以下是代码
```
int lemonadeChange(vector<int> bills) {
        int five = 0, ten = 0;
        for (int i : bills) {
            if (i == 5) five++;
            else if (i == 10) five--, ten++;
            else if (ten > 0) ten--, five--;
            else five -= 3;
            if (five < 0) return false;
        }
        return true;
    }
```
