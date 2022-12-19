因为移动两个位置代价为0
所以奇数移向奇数和偶数移向偶数，代价都为0；
最后剩下两个数相邻，
要想代价最小，就要让数量最少的筹码移向多的那一方。
所以解题思路：
1.需要计算出来奇数和偶数的个数
2.比较，并输出个数最少的
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd=0;
        int even=0;
        for(int i =0;i<chips.size();i++){
            if(chips[i]%2==0){
even++;
            }else{
odd++;
            }
        }
         
        return min(odd,even);
        
    }
};