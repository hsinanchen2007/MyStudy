### 解题思路
刚开始通过暴力实现，但是最后一组测试数据提示超时。所以想到以下方法来优化复杂度：

如果我们存入的数分别为a、b、c、d，存入的数的乘积为a * b  * c * d。假设我们现在需要求后两位的乘积，即c * d，那么我们可以利用a * b * c * d / a * b得出c*d的乘积。为什么要这样做呢？因为在录入数据的时候就可以维护一个乘积数组。这样就可以省去后面连乘的过程，只需要做一次除法就可以了。**这里需要注意的是**，0是需要特殊处理的。如果我们录入数据的时候遇到了0，我们就把当前乘积设置为1。为什么要这样做呢?假设我们在0之后，又录入了a、b、c、d（均不等于0），这个时候我们求后两位的乘积c * d，我们依然可以利用1 * a * b * c * d / a * b来得出结果。另一种情况就是，如果我们所求的最后k个数中包含了零，我们就可以直接返回0作为结果。为了可以提高这个效率，我们可以维护一个下标，用来记录0最后出现的位置。

### 代码

```c
typedef struct {
    int len, zeroIndex;
    int a[30000];
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *obj = (ProductOfNumbers *) malloc(sizeof(ProductOfNumbers));
	obj -> len = 0;
    obj -> zeroIndex = -1;
	return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    obj -> a[obj -> len] = num;
    if (num == 0) {
        obj -> zeroIndex = obj -> len; 
        obj -> a[obj -> len] = 1;   
    } else {
        obj -> a[obj -> len] = obj -> a[obj -> len - 1] * num;
    }
    (obj -> len)++;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (obj -> zeroIndex > obj -> len - k - 1) {
        return 0;
    } else {
        return obj -> a[obj -> len - 1] / obj -> a[obj -> len - k - 1];
    }
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    if (obj) {
        free(obj);
    }
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
```