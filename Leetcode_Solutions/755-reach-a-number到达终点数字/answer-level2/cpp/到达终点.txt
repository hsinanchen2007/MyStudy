### 解题思路
此处撰写解题思路

### 代码

```cpp
//数学
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int k=0;
        while(target>0){
            k++;
            target-=k;
        }
        return target%2==0?k:k+1+k%2;
    }
};
//BFS
class Solution {
public:
    int reachNumber(int target) {
        queue<pair<int,int> > pos;
        pos.push(make_pair(0,0));
        while(!pos.empty()){
            if(target==pos.front().first)
                return pos.front().second;
            else{
                int nowPos=pos.front().first;
                int step=pos.front().second;
                pos.push(make_pair(nowPos+step+1,step+1));
                pos.push(make_pair(nowPos-step-1,step+1));
                pos.pop();
            }
        }
        return -1;
    }
};


```