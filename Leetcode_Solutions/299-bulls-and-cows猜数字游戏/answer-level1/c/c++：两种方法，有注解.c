方法1：8ms

```
class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> mp;
        for (int i = 0; i < secret.size(); i++)
            mp[secret[i]]++;
        int bull = 0, cow = 0;
        for (int i = 0; i < guess.size(); i++){
            if (guess[i] == secret[i]){
                mp[guess[i]]--;
                bull++;
            }
        }
        for (int i = 0; i < guess.size(); i++){
            if (mp[guess[i]] != 0 && guess[i] != secret[i]){
                cow++;
                mp[guess[i]]--;
            } 
        }         
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
```
改进一下：

```
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        for (int i = 0; i < secret.size(); i++)
            mp[secret[i]]++;
        int bull = 0, cow = 0;
        for (int i = 0; i < guess.size(); i++){
            if (mp[guess[i]] != 0){
                cow++;
                mp[guess[i]]--;
            }
            if (guess[i] == secret[i])
                bull++;
        }        
        return to_string(bull) + "A" + to_string(cow - bull) + "B";
    }
};
```


方法2：4ms

```
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> v(10, 0);
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); i++){
            if (secret[i] == guess[i]){
                bull++;
                continue;
            }
            v[secret[i] - '0']++;
            v[guess[i] - '0']--;
        }
        for (int i = 0; i < 10; i++){
            if (v[i] > 0)
                cow += v[i];//数字不对（secret中没有）
        }
        /*只有3种情况：
        a.数字和位置都猜对
        b.数字猜对，位置不对
        c.数字不对（secret中没有）
        */
        cow = secret.size() - bull - cow;
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
```
