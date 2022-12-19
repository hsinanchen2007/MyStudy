### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        // if(x==0 || y==0)
        // {
        //     if(x==0 && y==0) return z==0;
        //     if(x==0) return z==y || z==0;
        //     if(y==0) return z==x || z==0;
        // }

        // int bigger=x, smaller=y;
        // if(y>x)
        // {
        //     bigger=y;
        //     smaller=x;
        // }

        // int cap1=bigger, cap1_rest=bigger%smaller;
        // int cap2=smaller, cap2_rest=smaller-cap1_rest;

        // return can_measure(cap1, cap1_rest, z, cap2) || can_measure(cap2, cap2_rest, z, cap1);

        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }

    // bool can_measure(int cap, int cap_rest, int z, int cap_in)
    // {
    //     if(cap_in==z) return true;
    //     if(cap_in > z)
    //     {
    //         return (z%cap==0) || ((z-cap_rest)%cap==0);
    //     }
    //     else
    //     {
    //         if(cap_in > cap_rest) return (z==(cap+cap_in)) || (z==(cap_rest+cap_in)) || (z==(cap+cap_rest));
    //         return (z==(cap+cap_in)) || (z==(cap_rest+cap_in));
    //     }
    // }

};
```