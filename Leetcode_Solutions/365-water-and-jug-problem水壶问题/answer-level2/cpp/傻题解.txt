### 解题思路
有点傻，不知道贝祖定理，想着a和b之间能通过交换来得到新的数，而新的数也可以分别和a,b交换来得到其他新的数。如果z能整除这些数的其中一个，那就可以通过很多次的交换得到z。但是可惜的是我忘了质量守恒定理了。。。。忘了限制if(x+y<z) return false;结果最后一个案例没有过。。。看了题解才反映过来。。。哎。。。

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
    int t=max(x,y);
    y=min(x,y);
    x=t;
    if(x+y==z) return true;
    if(x+y<z) return false;
    if(x==z|| y==z) return true;
    if(z==0) return true;
      if(y==0){
        if(x==z) return true;
        else return false;
    }
    int h,h2;
    h=x%y;
    cout<<x<<y;
    h2=y-h;
//    cout<<h;
//    cout<<h2;
    if(h==0) return false;
    if(z==h||z==h2||z%h==0||z%h2==0 ){
        return true;
    }

    while(y%h!=0){
//        cout<<h;
//        cout<<h2;
        h2=h-y%h;
        h=y%h;
        if(h==0) break;
        if(z==h||z==h2||z%h==0||z%h2==0 ){
            return true;
        }

    }
    while(x%h!=0){
//        cout<<h;
//        cout<<h2;
        if(h==0) break;
        if(z==h||z==h2||z%h==0||z%h2==0 ){
            return true;
        }
        h2=h-x%h;
        h=x%h;
    }
    return false;
}
};
```