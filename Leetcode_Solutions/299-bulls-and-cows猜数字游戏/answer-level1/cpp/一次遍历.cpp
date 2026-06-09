### 解题思路
此处撰写解题思路
相同位置ansA++；在secret出现的则++，guess出现的则--,并且都与0进行判断，在secret中若<0说明之前在guess出现ansB++,同理，在guess中也一样
### 代码

```cpp

class Solution {
public:
    string getHint(string secret, string guess)
    {
        int mp[10]={0,0,0,0,0,0,0,0,0,0};
        int len = secret.length();
        int ansA = 0,ansB = 0;
        for(int i = 0;i<len;i++){
            if(secret[i] == guess[i]) ansA++;
            else {
                if(mp[secret[i]-'0'] == 0) mp[secret[i]-'0'] = 1;
                else{
                    if(mp[secret[i]-'0']<0) ansB++;
                    mp[secret[i]-'0']++;
                }
                if(mp[guess[i]-'0'] == 0) mp[guess[i]-'0'] = -1;
                else{
                    if(mp[guess[i]-'0']>0) ansB++;
                    mp[guess[i]-'0']--;
                }
            }
        }
        return to_string(ansA)+'A'+to_string(ansB)+'B';
    }
};
```