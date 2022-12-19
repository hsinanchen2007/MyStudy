
只遍历一遍数组，对每个元素做如下计算：
（1）若该元素对60取余数为0，则nums_zeros的值加1；
（2）若该元素对60取余数不为0，则余数必然在[1,59]中，令a[i-1]记录余数为i的数的数量

那么满足题意总的歌曲对的数量由以下三部分组成：
（1）余数为0的数中取出两个不同数的组合的数量，即nums_zeros*(nums_zeros-1)/2;
（2）余数为1的数的数量×余数为59的数的数量+余数为2的数的数量×余数为58的数的数量+...+余数为29的数的数量×余数为31的数的数量,这些数量被维护在固定长度的数组a中(a[i]是余数为i+1的数的数量)
（3）余数为30的数中取出两个不同数的组合的数量，即a[29]*a[29]/2

返回以上三部分之和即可，代码如下：
```
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int num_zeros=0;
        int pairs=0;
        int tmp=0;
        int a[59]={0};
        for(int i=0;i<time.size();i++){
            tmp = time[i]%60;
            if(tmp==0)num_zeros++;
            else a[tmp-1]++;
        }
        for(int i=0;i<29;i++){
            pairs += a[i]*a[58-i];
        }
        return pairs+num_zeros*(num_zeros-1)/2+a[29]*(a[29]-1)/2;
    }
};
```
