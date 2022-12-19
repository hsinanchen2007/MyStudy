
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了92.93%的用户   

两个for循环
 int numJewelsInStones(string J, string S) {
        int amount[64] = {0};
        int res = 0 ;
        
        for(int i = 0 ; i < S.length() ; i ++){    
            amount[S[i]-'A'] ++ ;    
        }
        
        for(int i = 0 ; i < J.length() ; i ++){
            res += amount[J[i]-'A'];
        }
    
        return res ;

    }
