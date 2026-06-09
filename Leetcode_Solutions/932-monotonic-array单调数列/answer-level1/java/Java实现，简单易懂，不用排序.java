
![WX20191104-201203@2x.png](https://pic.leetcode-cn.com/bea89fa33772f780273552ee0b4f7d6e9675b3c18855a154765eaf62992b32ca-WX20191104-201203@2x.png)

看注释就能看懂了
```
public boolean isMonotonic(int[] A) {
        int upNum = 0;//记录数组递增次数
        int downNum = 0;//记录数组递减次数
        for (int i = 0; i < A.length-1; i++) {
            if (A[i] < A[i + 1]) {
                //前一个小于后一个，说明该数组单调递增
                if (downNum != 0){
                    //如果发现之前存在单调递减的情况，则直接返回false
                    return false;
                }else{
                    upNum++;//递增次数加一
                }
            }
            if (A[i] > A[i + 1]) {
                //前一个大于后一个，说明该数组单调递减
                if (upNum != 0) {
                    //如果发现之前存在单调递增的情况，则直接返回false
                    return false;
                }else{
                    downNum++;//递减次数加一
                }
            }
        }
        return true;
    }
```
