### 解题思路
此处撰写解题思路

### 代码

```c



bool canMeasureWater(int x, int y, int z){
    if(x+y==z||!z) return true;
    if(!x&&!y||x+y<z) return false;
    if(z%gcd(x,y)==0) return true;
    return false;
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
```