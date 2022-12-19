```
class Vector2D {
private:
    vector<vector<int>> :: iterator x;
    vector<int> :: iterator y;
    vector<vector<int>> cache;
    bool flag = true;
public:
    Vector2D(vector<vector<int>>& v) {
        if(v.empty()) {
            flag = false;
            return;
        }
        cache = v;
        int i = 0;
        while(cache[i].empty()){
            i++;
            if(i >= cache.size()) {
                flag = false;
                return;
            }
        }
        x = cache.begin() + i;
        y = x->begin();
    }
    
    int next() {
        int ret;
        ret = *y;
        y++;
        while(x!= cache.end() - 1 && y == x->end()){
            x++;
            y = x->begin();
        }
        return ret;
    }
    
    bool hasNext() {
        return flag && !(x == cache.end() - 1 && y == x->end());
    }
};

```
