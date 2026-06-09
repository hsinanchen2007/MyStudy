```
class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        set<string>vec;
        while(1){
            for(int i=0;i<tiles.size();i++){
                vec.insert(tiles.substr(0,i+1));
            }
            if(!next_permutation(tiles.begin(),tiles.end()))break;
            
        }
        return vec.size();
    }
};
```

使用next_permutation()函数