### 解题思路
数组法可以，代码如下。
取平均值法理论上可行，但没测试通。取平均值法的理论基础
选取较大值公式 ((a+b)+abs(a-b)) / 2 
选取较小值公式 (a+b - abs(a-b)) / 2 
### 代码
数组法
```c
int maximum(int a, int b){
    int arr[2]={a,b};
    return arr[b>a];
}
```