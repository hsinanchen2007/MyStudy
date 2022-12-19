### 解题思路
1、暴力-》超时
使用数组记录每盏灯的状态，0表示灭，1表示黄色，2表示蓝色
每次亮灯操作时，要遍历所有灯来更新灯的状态；
最后判断所有的状态是不是2来得出结论

2、等差数列
符合情况的时刻，已亮的灯的编号肯定是符合等差数列的，所以，只要保存每次亮灯的编号，然后计算和是否等于等差数列的和即可

注意：求和时会int会溢出
### 代码

```java
class Solution {
    public int numTimesAllBlue(int[] light) {
        double sum = 0;
        int res = 0;
        for (double i = 0; i < light.length; i++) {
            sum += light[(int)i];
            if (sum == (i + 1) / 2 * (i + 2)) {
                res ++;
            } else {
                System.out.println(sum);
                System.out.println(((i + 1) * (i + 2)) /2);
            }
        }
        System.out.println(res);
        return res;
    }
}
```
3、最大编号
符合情况的时刻，已亮的灯的编号肯定是符合等差数列的，同时，最大编号的灯也会等于亮灯的次数，所以只需记录灯的最大编号和亮灯次数进行比较即可
### 代码

```java
class Solution {
    public int numTimesAllBlue(int[] light) {
        int max = 0;
        int res = 0;
        for (int i = 0; i < light.length; i++) {
            max = Math.max(max, light[i]);
            if (max == i + 1) {
                res++;
            }
        }
        return res;
    }
}
```