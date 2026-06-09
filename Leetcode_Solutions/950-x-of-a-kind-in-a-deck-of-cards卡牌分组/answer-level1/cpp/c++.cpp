### 解题思路
解题思路简单，就是不知道为啥别人这么快，头秃

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<2)return false;
        int res=0;
        vector<int> map(10001,0);
        for(int num:deck){
            map[num]++;
        }
        for(int i=0;i<10001;i++){
            if(map[i]!=0){
                res=gcd(map[i],res);
                if(res<2)return false;
            }
        }
        return true;
    }

};
```