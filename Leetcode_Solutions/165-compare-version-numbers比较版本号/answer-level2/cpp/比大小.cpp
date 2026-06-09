class Solution {
public:
    int compareVersion(string v1, string v2) {
        int p1 = 0,p2 = 0;
        int num1 = 0,num2 = 0;
**        
        执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.4 MB
, 在所有 C++ 提交中击败了
35.22%
的用户**
while(p1 < v1.size() || p2 < v2.size()){
            while(p1 < v1.size() && v1[p1] != '.'){
                num1 = num1 * 10 + v1[p1] - '0';
                p1++;
            }
            
        while(p2 < v2.size() && v2[p2] != '.'){
            num2 = num2 * 10 + v2[p2] - '0';
            p2++;
        }    
        
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
            num1 = 0;
            num2 = 0;
        p1++;
            p2++;
        }
        return 0;
        
    }
};