计算方法如下：
+ 公牛=相同位置的相同字符数
+ 母牛=两子串相同字符数-公牛数

两子串相同字符数需要先遍历一次secret，储存字符信息(每个字符多少个)。然后再遍历一次guass,更新字符信息(如果guass[i]出现过就减一)

相同位置的相同字符数遍历一次即可。总共O(3n)

12ms 49.10%
```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> v(10,0);
        int count1=0,count2=0;
        for(auto p:secret){//存储字符信息
            v[p-'0']++;
        }
        for(auto q:guess){//更新字符信息
            if(v[q-'0']){
                count1++;
                v[q-'0']--;
            }
        }
        
        for(int i=0;i<secret.size();i++){//找公牛
            if(secret[i]==guess[i]) count2++;
        }
        
        return to_string(count2)+"A"+to_string(count1-count2)+"B";
        
    }
};
```