**方法一：二分查找法**
```
class Solution {
    /**
    * 思路：
    * 想明白题目中x的平方根取整数部分在x中的范围，然后使用二分查找。
    * 当正整数x>=2时，它的整数平方根a一定小于或者等于x/2且大于0，即0<a<=x/2。
    * 由于a一定是整数，此问题可以转换成在有序整数集中寻找一个特定值，因此可以使用二分查找。 
    */
    public int mySqrt(int x) {
        if(x <= 0){
            return 0;
        }else if(x == 1){
            return 1;
        }
        long num;
        int mid, l = 2, r = x/2;
        while(l <= r){
            mid = (l + r) / 2;
            num = (long)mid * mid;
            if(num > x){
                r = mid - 1;
            }else if(num < x){
                l = mid + 1;
            }else{
                return mid;
            }
        }
        return r;
    }
}
```

**方法二：牛顿法**
```
class Solution {
    /**
    * 思路：
    * 由题假设k为x的平方根，当k和x/k无限接近差小于1时候得到k值。
    * 如果k不接近确切平方根，则k和x/k的平均值0.5*(k+x/k)更接近确切平方根，直至k和x/k差小于1(两数之间没有其它整数)。
    */
    public int mySqrt(int x) {
        if(x <= 0){
            return 0;
        }

        double x0 = x;
        double x1 = (x0 + x/x0)/2.0;
        while(Math.abs(x0 - x1) >= 1){
            x0 = x1;
            x1 = (x0 + x/x0)/2.0;
        }
        return (int)x1;
    }
}
```
