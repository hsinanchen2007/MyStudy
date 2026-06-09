```
class ProductOfNumbers {
    public:
    int mult[40010],isZeroPos,n;//前缀连乘积(且把0视为1)
    ProductOfNumbers() {
        n = 0;//当前添加的数的下标
        isZeroPos = 0;//若包含该下标 则连乘积为0
        mult[0] = 1;
    }
    void add(int num) {
        ++n;
        if(num == 0) 
            isZeroPos = n, mult[n] = 1;//更新0点,因为该点对后面的数的乘积无影响故令此处连乘积为 1
        else mult[n] = mult[n-1]*num; 
    }
    int getProduct(int k) {
        k = n-k+1;//也就是从前往后数的第n-k+1个数
        if(k <= isZeroPos) return 0;//包含了0 所以连乘积一定为0
        else return mult[n]/mult[k-1];//若不包含0 则为k~n的连乘积=1~n的连乘积/1~k-1的连乘积
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
```