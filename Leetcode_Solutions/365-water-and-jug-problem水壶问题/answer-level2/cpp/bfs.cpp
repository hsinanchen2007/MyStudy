### 解题思路
bfs

### 代码

```cpp
typedef pair<int,int> PII;
class Solution {
private:
    set<PII> done;
public:
    Solution()
    {
        done.clear();
    }
    //bfs 剪枝
    bool bfs(int x,int y,int z)
    {
        queue<PII> pq;
        while(!pq.empty()) pq.pop();
        pq.push(make_pair(0,0));
        done.insert(make_pair(0,0));
        pq.push(make_pair(x,y));
        done.insert(make_pair(x,y));
        while(!pq.empty())
        {
            PII now = pq.front();
            pq.pop();
            if(now.first+now.second==z) return true;
            //进行三种尝试
            if(done.count(make_pair(x,now.second))==0) {
                pq.push(make_pair(x,now.second));
                done.insert(make_pair(x,now.second));
            }
            if(done.count(make_pair(now.first,y))==0) {
                pq.push(make_pair(now.first,y));
                done.insert(make_pair(now.first,y));
            }
            if(done.count(make_pair(0,now.second))==0) {
                pq.push(make_pair(0,now.second));
                done.insert(make_pair(0,now.second));
            }
            if(done.count(make_pair(now.first,0))==0) {
                pq.push(make_pair(now.first,0));
                done.insert(make_pair(now.first,0));
            }
            //从一个水壶向另一个水壶倒水，直到装满或者倒空
            //从第一个向第二个倒水
            int k = y - now.second;
            if(now.first>=k) {
                if(done.count(make_pair(now.first-k,y))==0) {
                    pq.push(make_pair(now.first-k,y));
                    done.insert(make_pair(now.first-k,y));
                }
            }
            else {
                if(done.count(make_pair(0,now.second+now.first))==0) {
                    pq.push(make_pair(0,now.second+now.first));
                    done.insert(make_pair(0,now.second+now.first));
                }
            }
            k = x - now.first;
            if(now.second>=k) {
                if(done.count(make_pair(x,now.second-k))==0) {
                    pq.push(make_pair(x,now.second-k));
                    done.insert(make_pair(x,now.second-k));
                }
            }
            else {
                if(done.count(make_pair(now.first+now.second,0))==0) {
                    pq.push(make_pair(now.first+now.second,0));
                    done.insert(make_pair(now.first+now.second,0));
                }
            }
        }
        return false;
    }
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z) return false;
        if(x+y==z||z==0) return true;
        return bfs(x,y,z);
        return false;
    }
};
```