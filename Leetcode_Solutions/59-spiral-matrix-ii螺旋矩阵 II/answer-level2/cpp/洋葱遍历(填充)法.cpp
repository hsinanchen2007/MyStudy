* 文中借用了别人的图片，先声明一下 [图片的出处：一种优雅的遍历方式，使代码整齐易读](https://leetcode-cn.com/problems/spiral-matrix/solution/yi-chong-you-ya-de-bian-li-fang-shi-dai-ma-zheng-q/)  
## 自己的遍历方式
* 像剥洋葱一样，一圈一圈地去遍历(填充)矩阵，细节是魔鬼，以下代码的注释中提到了注意点，只要注意就能避免遍历(填充)出错  
* 遍历过程如下面的ASCII示意图所示  
```
(0,0)------------------->(0,n)
 (1,0)(1,1)------->(1,n-1)  |
  ↑ (2,1)-->......    |    | 
  |   ↑               |    | 
  |   |               ↓    |
  |  (n-1,1)<---(n-1,n-1)  ↓
(n,0)<-------------------(n,n)
```
```
vector<vector<int>> generateMatrix(int n) { 
    vector<vector<int>> res(n, vector<int>(n)); 
    //s,e表示每圈矩阵的开始索引和结束索引，m表示填充的值，循环的结束条件是s>e
    for(int s = 0, e = n - 1, m = 1; s<=e ; s++,e--){
        //从左到右横向 
        for (int j = s; j <= e; j++) res[s][j] = m++;
        //从上到下纵向，注意：i 从s+1开始
        for (int i = s+1; i <= e; i++) res[i][e] = m++;
        //从右到左横向，注意：j 从e-1开始
        for (int j = e-1; j >= s; j--) res[e][j] = m++;
        //从下到上纵向，注意：i 从e-1开始，到s+1结束 !!
        for (int i = e-1; i >= s+1; i--) res[i][s] = m++;
    }
    return res;
}
```
## 更优雅的遍历方式
* 后来在 54.螺旋矩阵 浏览题解的时候看到这样一张图，感觉这是一种更加优雅的遍历顺序，值得自己借鉴与实现出来。  
![](https://pic.leetcode-cn.com/5254ec0ff6bec6d954e9abea05d92d8cdcd5136662d2695883bf9d167d8658a9-2019-07-27_124436.jpg)
[图片的出处：一种优雅的遍历方式，使代码整齐易读](https://leetcode-cn.com/problems/spiral-matrix/solution/yi-chong-you-ya-de-bian-li-fang-shi-dai-ma-zheng-q/)
```
//结构上更优雅的代码
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    for(int s = 0, e = n - 1, m = 1; s<=e ; s++,e--){
        if(s==e) res[s][e] = m++;
        for (int j = s; j <= e-1; j++) res[s][j] = m++;
        for (int i = s; i <= e-1; i++) res[i][e] = m++;
        for (int j = e; j >= s+1; j--) res[e][j] = m++;
        for (int i = e; i >= s+1; i--) res[i][s] = m++;
    }
    return res;
}
```
