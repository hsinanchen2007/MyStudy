# 解决思路

每个多米诺牌只有3种可能状态：向左倒，向右倒，或者中立。


在一开始，有些牌已经倒了，有些牌还处于中立的状态。


已经倒了的牌，不能恢复中立或者改变倒的方向，所以它们开始时什么状态，结束时还是什么状态。


这些在一开始就已经倒了的牌，将整排多米诺划分为若干个连续的中立牌序列。


以`.L.R...LR..L..`这一初始序列为例，它有5个连续的中立牌序列：`[0，1),[2，3),[4，7),[9，11),[12，14)`。


对每一个中立牌序列，设其起始位置为`start`, 结束位置为`end`, 则可以分以下情况讨论：



1.`start == 0 && end == n`:
此时表示整个序列都是中立牌，那么结束时依然保持原样。



2.`start == 0 && end < n`:
此时表示中立牌序列从0开始，到`end`结束。
如果第`end`张多米诺是向左倒的，那么这个中立牌序列`[0,end)`中的所有牌，结束时都会向左倒；
如果第`end`张多米诺是向右倒的，那么这个中立牌序列`[0,end)`中的所有牌，结束时都会保持中立；



3.`start > 0 && end == n`:
此时表示中立牌序列从start开始，到数组末尾结束。
如果第`start-1`张多米诺是向左倒的，那么这个中立牌序列`[start,n)`中的所有牌，结束时都会保持中立；
如果第`start-1`张多米诺是向右倒的，那么这个中立牌序列`[start,n)`中的所有牌，结束时都会向右倒；



4.`start > 0 && end < n`:
如果第`start-1`张和第`end`张同向左（右）倒，则`[start,end)`中所有牌都向左（右）倒；
如果第`start-1`张向左，第`end`张向右，则`[start,end)`中所有牌中立；
如果第`start-1`张向右，第`end`张向左，则`[start,end)`中左面一半的牌向右倒，右面一半的牌向左倒，中间那张（如果有的话）中立。


# 实现代码
```
class Solution {
public:
    string pushDominoes(string dominoes) {
        string res;
        int n = dominoes.length();
        if (n == 0)
            return res;

        int start = 0, end = 0;
        while (start < n){
            // 一开始就倒了的牌，结束时状态保持不变，所以直接加入结果数组
            if (dominoes[start] != '.')
                res += dominoes[start++];
            else{
                end = start;
                // 找到中立牌序列[start,end)
                while (end < n && dominoes[end] == '.')
                    end ++;
                // 分4种情况讨论
                if (start == 0 && end == n){
                    for (int i = 0;i < n;i ++)
                        res += '.';
                    return res;
                }
                else if (start == 0){
                    if (dominoes[end] == 'L')
                        for (int i = 0;i < end;i ++)
                            res += 'L';
                    else 
                        for (int i = 0;i < end;i ++)
                            res += '.';
                    res += dominoes[end];
                    start = end + 1;
                }
                else if (end == n){
                    if (dominoes[start-1] == 'R')
                        for (int i = 0;i < n-start;i ++)
                            res += 'R';
                    else
                        for (int i = 0;i < n-start;i ++)
                            res += '.';
                    return res;
                }
                else {
                    if (dominoes[start-1] == 'L' && dominoes[end] == 'L')
                        for (int i = 0;i < end - start;i ++)
                            res += 'L';
                    else if (dominoes[start-1] == 'L' && dominoes[end] == 'R')
                        for (int i = 0;i < end - start;i ++)
                            res += '.';
                    else if (dominoes[start-1] == 'R' && dominoes[end] == 'L'){
                        for (int i = start;i < (end + start) / 2;i ++)
                            res += 'R';
                        if ((end+start) % 2 != 0){
                            res += '.';
                            for (int i = (end + start)/2+1;i < end;i ++)
                                res += 'L';
                        }
                        else
                            for (int i = (end + start)/2;i < end;i ++)
                                res += 'L';
                    }
                    else 
                        for (int i = 0;i < end - start;i ++)
                            res += 'R';
                    res += dominoes[end];
                    start = end + 1;
                }
            }
        }
        return res;
    }
};
```
