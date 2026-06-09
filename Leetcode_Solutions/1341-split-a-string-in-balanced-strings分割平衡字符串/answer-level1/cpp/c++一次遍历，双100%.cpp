依次遍历，只要R与L的个数相等，就分割一次。

class Solution {
public:
    int balancedStringSplit(string s) {
        
    
        int l = 0;                  //记录L个数
        int r = 0;                  //记录R的个数
        int count =0;               //记录有多少对
        for(int i = 0;i<s.size();i++){          //依次遍历，记录R与L的个数
        if(s[i] == 'L'){ l++; }
            else{r++;}
            
            if( r==l){         //当R与L的个数相等，count++，重新开始计算
                count++;
                r = l = 0;
            }
        }
        return count;
    }
};