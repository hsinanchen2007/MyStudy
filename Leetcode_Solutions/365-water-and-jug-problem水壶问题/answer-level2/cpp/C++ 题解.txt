### 解题思路
此处撰写解题思路
一开始的思路是从x和y的倍数关系，以及奇偶关系入手，发现有些用例无法通过；后来发现其实只要找出x和y的最大公因数就可以解决。而且发现了求两个数最大公因数的欧几里得法，算是小有收获。（代码有很多不足，希望以后能变得更厉害）
### 代码

```cpp
class Solution {
private:
    int maxNum;
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z==0) return true;
        if (x==0) return z==y;
        if (y==0) return z==x;
        maxNum=x+y;
        if (z>maxNum) return false;
        int num=gcf(x,y);
        int i=0;
        while(i<=maxNum){
            if(z==i) return true;
            i+=num;
        }
        return false;
    }
    int gcf(int x, int y){
        if (y==0) return x;
        return gcf(y, x%y);
    }
};
```