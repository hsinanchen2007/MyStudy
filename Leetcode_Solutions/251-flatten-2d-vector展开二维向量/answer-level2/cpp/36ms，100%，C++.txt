### 解题思路
由于v中可能存在为空的vector<int>元素，因此判断hasNext()使不能直接判断当前下标向后推1的元素是否存在，通过for双层循环只要能运行到内层循环即可证明当前位置存在元素，返回true，并更新next元素的下标，但由于不清楚源代码是否在调用next()前调用hasNext()，因此在next中需要手动调用一遍更新下标后即可
### 代码

```cpp
class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        ridx = cidx = 0;
        this->v = v;
    }
    
    int next() {
        hasNext();
        return v[ridx][cidx++];
    }
    
    bool hasNext() {
        for(int i = ridx; i < v.size(); ++i){
            for(int j = cidx; j < v[i].size(); ++j){
                ridx = i;
                cidx = j;
                return true;
            }
            cidx = 0;
        }
        return false;
    }
private:
    vector<vector<int>> v;
    int ridx, cidx;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```