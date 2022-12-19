有两点不严谨：
1.都说是二维向量了,测试用例里竟然还有一维的空向量[]，本来构造函数Vector2D里可以直接y=v[0].begin();现在需要判断v不为空。
2.题中描述有连续next、next...的测试用例,竟然没有下面的测试用例
![image.png](https://pic.leetcode-cn.com/63e047660f7ff6b0168513d177517d2098fe10e7623f1689b1d03428b5532311-image.png)
![image.png](https://pic.leetcode-cn.com/7a4a58e228977e1386c06f287451ff06e84a70566fadbd669f972843ffdf91bb-image.png)

```
class Vector2D {
private:
    vector<vector<int>>::iterator x;
    vector<int>::iterator y;
    vector<vector<int>>::iterator xend;
public:
    Vector2D(vector<vector<int>>& v) {
        x=v.begin();
        xend=v.end();
        if(x!=xend) y=v[0].begin();
    }
    
    int next() {
        assert(hasNext());
        return *(y++);
    }
    
    bool hasNext() {
        while(x!=xend){
            if(y==(*x).end()){
                x++;
                if(x==xend) return false;
                y=(*x).begin();
            }
            else{
                return true;
            }
        }
        return false;
    }
};

```
