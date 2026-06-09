**思路**
1. 新建一个类Data，包含pos和speed两个属性，然后新建这个类对象数组datas；
2. 对datas根据pos从小到大排序；
3. 然后从大到小遍历datas数组，不断的判断当前车是否能够与行驶在前面的车队相遇，若能相遇，则将其并到前面车队中，否则当前车另起一个车队。

**如何判断是否能够相遇**
- 位置小的车要超过行驶在前面位置大的车，必须速度大一点，然后判断相遇的地点是否在终点target之前，若在target之前，说明能够相遇。

**注意事项**
题目说了 **一辆车永远不会超过前面的另一辆车，但它可以追上去，并与前车以相同的速度紧接着行驶** ，因此，在从位置大的往位置小遍历过程中，我们只需要判断是否能追的上最近的车队即可。因为，假设当前车前面有[车队A，车队B]，既然是两个车队，说明车队A追不上车队B，因此假设当前车追不上车队A，那么他一定追不上车队B。

```java
public class Problem853 {

    class Data {
        int position;
        int speed;
        Data(int position, int speed) {
            this.position = position;
            this.speed = speed;
        }
    }

    private boolean isMeet(Data data1, Data data2, int target) {
        if (data1.speed <= data2.speed) {
            return false;
        }

        double t = (data2.position - data1.position) * 1.0 / (data1.speed - data2.speed);
        return data1.speed * t + data1.position <= target;
    }

    public int carFleet(int target, int[] position, int[] speed) {
        int len = position.length;
        if (len == 0) {
            return 0;
        }
        Data[] datas = new Data[len];

        for (int i = 0; i < len; i++) {
            datas[i] = new Data(position[i], speed[i]);
        }

        Arrays.sort(datas, Comparator.comparingInt(o -> o.position));

        int ans = 1;
        Data frontCar = datas[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            if (!isMeet(datas[i], frontCar, target)) {
                ans++;
                frontCar = datas[i];
            }
        }

        return ans;
    }

}
```
**复杂度分析**
时间复杂度：$O(nlogn)$。因为存在排序。
空间复杂度：$O(n)$。
