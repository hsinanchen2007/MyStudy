### 解题思路
        用两个递增的整数来放入队列，主要是我不会用pair，看官解才学会
        所以每次队列放入的是一个结构，然后因为只往右和下递增，所以直接用了一维数组来存储是否访问过。

### 代码

```cpp
class Solution {
    struct node{
        int x;
        int y;
        node(int a,int b):x(a),y(b){}
    };
    int dx[4]={0,1},dy[4]={1,0};
public:
    int movingCount(int m, int n, int k) {
        queue<node*>q;
        q.push(new node(0,0));
        int conut=0;
        vector<int>compare(m,-1);
        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            int number=num(temp->x)+num(temp->y);
            if(number<=k)
            ++conut;
            for(int i=0;i<2&&number<=k;++i){
                int tx=temp->x+dx[i],
                    ty=temp->y+dy[i];
                if(tx<m && ty<n && compare[tx]<ty){
                    compare[tx]=ty;
                    node* p1=new node(tx,ty);
                    q.push(p1);
                }
            }
            delete temp;
        }
        return conut;
    }
    int num(int t){
        int temp=0;
        while(t!=0){
            temp=temp+t%10;
            t/=10;
        }
        return temp;
    }
};
```