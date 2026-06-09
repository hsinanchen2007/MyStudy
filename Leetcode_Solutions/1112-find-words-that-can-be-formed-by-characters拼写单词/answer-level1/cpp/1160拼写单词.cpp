### 解题思路
像是堆排序，把每个字母个数存出来比较就可以了。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int w[26] = {0};
        for(int i = 0 ; i < chars.length() ; i++){
            w[ chars[i] - 'a'] ++;
        }
        
        int ans = 0;
        for(int i = 0 ; i < words.size() ; i++){
            int t[26]={0};
            for(int j = 0 ; j < words[i].length() ; j++){
                t[ words[i][j] - 'a' ] ++;
            }
            bool flag = true;
            for(int j = 0 ; j < 26 ; j++){
                if(t[j] > w[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                ans+=words[i].length();
            }
        }
        return ans;
    }
};
```