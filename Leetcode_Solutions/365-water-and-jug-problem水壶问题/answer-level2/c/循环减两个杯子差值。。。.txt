### 解题思路
1. 只能用两个杯子，所以z>s+l不行。
2. 如果z是s或l或s+l，则ok
3. 如果有一个杯子是0（黑人问号）， 则看z是否等于另外一个杯子
4. 如果z比最大的杯子大，则问题转换为(x,y,z-fmax(x,y))
5. 否则挨个做减法，减出来z则ok

### 代码

```c
bool canMeasureWater(int x, int y, int z){
    int s = fmin(x,y);
    int l = fmax(x,y);

    if (z > s+l) return false;
    if (z == s || z == l || z == s+l) return true;

    if (s == 0) return (z == l);

    if (z > l) {
        return canMeasureWater(s, l, z-l);
    }

    if ((z > s && z < l) || (z < s)) {
        int left = l;
        while (left > 0) {
            left = (left >= s) ? (left - s) : (left + l - s);
            if (left == z) return true;
        }
        return false;
    }

    return false;
}
```