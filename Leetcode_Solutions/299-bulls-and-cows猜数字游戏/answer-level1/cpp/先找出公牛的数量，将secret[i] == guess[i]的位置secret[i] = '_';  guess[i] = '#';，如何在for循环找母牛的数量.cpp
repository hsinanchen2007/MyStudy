### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int  pose = 0;
        int sum = 0;
        for (int i = 0;i < secret.size();i++)
        {
            if (secret[i] == guess[i])
            {
                sum++;
                secret[i] = '*';
                guess[i] = '#';
            
            }
          }
            for(int i=0;i<secret.size();i++)
            {
                int j = secret.find(guess[i]);
                if ( j!= secret.npos)
                {
                    secret[j] = '*';
                    pose++;
                    
                }
            } 
           
        return to_string(sum)+"A"+to_string(pose)+"B";  
    } 
};
```