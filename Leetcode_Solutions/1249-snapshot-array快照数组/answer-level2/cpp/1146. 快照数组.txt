![QQ图片20191113105630.png](https://pic.leetcode-cn.com/cc6ef7682e660c2622bbecd9e0093b18b42ecca160f1a5347b918caf13eb98d3-QQ%E5%9B%BE%E7%89%8720191113105630.png)

```
class SnapshotArray {
private:
    int id;
    vector<vector<pair<int,int>>> s;
public:
    SnapshotArray(int length) {
        s=vector<vector<pair<int,int>>>(length,vector<pair<int,int>>(1,make_pair<int,int>(0,0)));
        id=0;
    }
    
    void set(int index, int val) {
        int i=s[index].size()-1;
        if(s[index][i].first==id)
        {
            s[index][i].second=val;
        }
        else
        {
            s[index].emplace_back(pair<int,int>(id,val));
        }
    }
    
    int snap() {
        int res = id++;
        return res;
    }
    
    int get(int index, int snap_id) {
        int low=0;
        int high=s[index].size()-1;
        if(s[index][high].first<=snap_id)
        {
            return s[index][high].second;
        }
        while(low<high)
        {
            int mid=(low+high+1)>>1;
            if(s[index][mid].first<=snap_id)
            {
                low=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        return s[index][low].second;
    }
};
```
