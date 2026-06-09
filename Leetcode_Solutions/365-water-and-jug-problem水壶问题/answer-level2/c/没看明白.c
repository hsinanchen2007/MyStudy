### 解题思路
此处撰写解题思路

### 代码

```c
int GCD(int a,int b){
    return a%b==0?b:GCD(b,a%b);
}

bool canMeasureWater(int x, int y, int z){
    if(x==0&&y==0) return z==0;
    if(z>x+y) return false;
    int a=y==0?GCD(y,x):GCD(x,y);
    return z%a==0;
}

```