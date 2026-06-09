第一次写题解，瑟瑟发抖，还请各位指教……

拿到这题最初的想法是，要么每次product操作时直接执行k个数的乘法，要么在add操作里维护一个乘积数组（也就是说，每添加一个数num，乘积数组里的每个数都乘以num）。

```
方法一
class ProductOfNumbers {
public:
    vector<int> nums;
    int n=0;
    ProductOfNumbers() {

    }

    void add(int num) {
        nums.push_back(num);
        ++n;
    }

    int getProduct(int k) {
        int ans=1;
        for(int i=0;i<k;++i)
            ans*=nums[n-1-i];
        return ans;
    }
};
```


```
//方法二
class ProductOfNumbers {
public:
    vector<int> nums;
    vector<int> products;
    
    ProductOfNumbers() {

    }

    void add(int num) {
        nums.push_back(num);
        products.push_back(num);
        int n = products.size();
        for (int i = 0; i < n - 1; ++i)
            products[i] *= num;
    }

    int getProduct(int k) {
        return products[nums.size() - k];
    }
};
```


前一种方法保证了add操作的O（1）复杂度，但是product操作则是O（k）复杂度；
后一种方法保证了product操作的O（1）复杂度，但是add操作则是O（nums.length）复杂度。


超时以后，我开始思考如何降低时间复杂度，思考过程是，第一种方法复杂度高的原因在于没有用空间换时间，换言之，没有把一些有用的中间结果存储下来，而是每次暴力的重新计算乘积；第二种方法复杂度高的原因在于每次要更新的中间结果太多，也就是每add一个数字，要把product数组里的所有数字都更新一遍，能不能只更新一个数呢？

要想只更新一个数，本质上来说，就要求改变product数组的定义——要求乘积数组里的每个位置的数字只和前面的数有关，后面添加多少新的值都与我无关！
**因此，我将product[i]的定义，从num数组后n-i个数的乘积，改为num数组前i+1个数的乘积。**
这样，
add操作时，只需要在product数组中新添加一个product[n-1]*num；
product操作时，返回products[n - 1] / products[n - k - 1]。

需要注意的是，当add 0发生时，需要特殊处理，不然在后续的product操作中会出现除0错误。
具体怎么修改代码我就不说啦，先去吃饭。把代码贴在这里，大家可以评论意见，做得更好。

```
class ProductOfNumbers {
public:
    vector<int> nums;
    vector<int> products;
    int n = 0;
    int locOf0 = -1;
    ProductOfNumbers() {

    }

    void add(int num) {
        nums.push_back(num);
        if (num == 0) {
            locOf0 = n;
            products.push_back(1);
        }
        else if (n == 0 || (locOf0 == n - 1)) {
            products.push_back(num);
        }
        else {
            products.push_back(num * products[n - 1]);
        }
           
        ++n;
        cout<<"add num="<<num<<", n="<<n<<", locOf0="<<locOf0<<endl;
    }

    int getProduct(int k) {
        
        cout<<"getProduct k="<<k<<", n="<<n<<", locOf0="<<locOf0<<endl;
        if (locOf0 + k <= n - 1) {
            if (k == n)
                return products[n - 1];
            else
                return products[n - 1] / products[n - k - 1];
        }
        else
            return 0;
    }
};
```
