/**

求 Chou(n)表示第n个丑数，第n个丑数等于之前的丑数（不是同一个）乘2、3、5的最小值；
    **Chou(n) = min(Chou(x)\*2、Chou(y)\*3、Chou(z)\*5)**
    当最小值等于Chou(x)*2、Chou(y)*3、Chou(z)*5则将丑数x、y、z向后移一位
分析：  
特殊：1为丑数
    2 min(Chou(1)*2, Chou(1)*3, Chou(1)*5) --2
    3 min(Chou(1)*3, Chou(1)*5, Chou(2)*2) --3
    4 min(Chou(1)*5, Chou(2)*2, Chou(2)*3) --4
    5 min(Chou(1)*5, Chou(3)*2, Chou(2)*3) --5
    6 min(Chou(2)*5, Chou(3)*2, Chou(2)*3) --6
    7 min(Chou(2)*5, Chou(4)*2, Chou(3)*3) --8
    8 min(Chou(2)*5, Chou(5)*2, Chou(3)*3) --9
 */
```
var nthUglyNumber = function(n) {
    let l2=0, l3=0, l5=0, arr=new Array(n);
    arr[0]=1;
    for (let i=1; i<n; i++) {
        let min = Math.min(arr[l2]*2, arr[l3]*3, arr[l5]*5);
        arr[i] = min;
        if (min==arr[l2]*2) {
            l2++;
        }
        if (min==arr[l3]*3) {
            l3++;
        }
        if (min==arr[l5]*5) {
            l5++;
        }
    }
    return arr[n-1];
 };
```