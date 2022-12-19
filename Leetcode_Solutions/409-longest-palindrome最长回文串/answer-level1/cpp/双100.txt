### 解题思路
规律： 看每个字母的个数： 个数是偶数的字母：全加， 个数是奇数的字母：加最大的偶数。 
        最后，中间可以放一个任意字母 故+1（在有 个数是奇数的字母时才加）


注意 大小写分开， +1 是最后+1

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int alpNum[26] = {0, }; // 26个字母，初始化数目0
        int alphaUp[26] = {0, };
        int i, sum = 0;

        for (i=0; i<s.size(); i++){
            if (s[i] >= 'a'){
                alpNum[s[i]-'a'] ++;
            }
            else{
                alphaUp[s[i]-'A'] ++;
            }
           
          
        }

        int evenNum = 0, jiNum = 0;
        for (i=0; i<26; i++){
            if (alpNum[i] != 0 ){
                if (alpNum[i]%2 == 0)       // 注意奇偶 的问题中  
                    evenNum += alpNum[i];   // 偶数个字母 全加
                else{
                    evenNum += alpNum[i] -1; // 奇数个字母 只加最大偶数
                     jiNum ++;
                }
                
            }    
        }
        
        cout<< evenNum << " " << jiNum << endl;
       

        sum += evenNum;

        // up
        evenNum = 0;
        for (i=0; i<26; i++){
            if (alphaUp[i] != 0 ){
                if (alphaUp [i]%2 == 0)       // 注意奇偶 的问题中  
                    evenNum += alphaUp[i];   // 偶数个字母 全加
                else{
                    evenNum += alphaUp[i] -1; // 奇数个字母 只加最大偶数
                     jiNum ++;
                }
                
            }    
        }
        
        if (jiNum > 0 )
            evenNum ++;


        return sum + evenNum;

    }
};
```