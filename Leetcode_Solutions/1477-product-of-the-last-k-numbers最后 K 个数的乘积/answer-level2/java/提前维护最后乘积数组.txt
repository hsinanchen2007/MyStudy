```java
class ProductOfNumbers {
    private int di; // data index
    private int[] prod; // 提前维护最后k个数乘积数组

    public ProductOfNumbers() {
        di = 0;
        prod = new int[40000]; // 题目给出的最大长度
        Arrays.fill(prod, 1); // 默认1，方便做乘法
    }

    public void add(int num) {
        di++;
        if (num == 1) return;
        if (num == 0) Arrays.fill(prod, 0, di, 0);
        else for (int i = 0; i < di; i++) prod[i] *= num; // 直接怼..
    }

    public int getProduct(int k) {
        return prod[di - k];
    }
}
```
