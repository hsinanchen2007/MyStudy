##### 设当前时刻为k，则满足下列条件时，时刻k能够让所有开着的灯都变成蓝色：

$$\sum_{r=0}^{k}r+1 = \sum_{r=0}^{k}light[r]$$
##### 也即:
$$\sum_{r=0}^{k}(r+1 - light[r]) = 0$$

##### 代码实现：
```
public int numTimesAllBlue(int[] light) {
    int sum = 0;
    int num = 0;
    for (int i = 0; i < light.length; i++) {
      sum += i + 1 - light[i];
      if (sum == 0) {
        num++;
      }
    }

    return num;
  }
```