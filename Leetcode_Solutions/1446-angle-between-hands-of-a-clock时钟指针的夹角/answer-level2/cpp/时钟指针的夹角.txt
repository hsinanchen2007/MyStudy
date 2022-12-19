####  方法一：数学
其思想是分别计算 0 点垂线与每个指针之间的角度。答案是这两个角度的差。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTM0NC9kaWZmLnBuZw?x-oss-process=image/format,png)

**分针的角度：**
我们从分针开始，整个圆 $360°$ 有 60 分钟。分针指针移动一分钟的角度是 $1 \text{ min} = 360° / 60 = 6°$。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTM0NC9vbmVfbWluMi5wbmc?x-oss-process=image/format,png)
现在可以很容易地找到 0 点垂直线和分钟指针之间的角度：$\text{minutes\_angle} = \text{minutes} \times 6°$。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTM0NC9xcV9taW4yLnBuZw?x-oss-process=image/format,png)

**时针的角度：**
与分针的角度相似，整个圆 $360°$ 有 12 个小时，因此每个小时 $1 \text{h} = 360° / 12 = 30°$。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTM0NC9ob3VyLnBuZw?x-oss-process=image/format,png)
则时针的角度为：$\text{hour\_angle} = \text{hour} \times 30°$。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTM0NC9xcV9oLnBuZw?x-oss-process=image/format,png)
由于 12 点的角度实际为 0，则需要修改表达式为：$\text{hour\_angle} = (\text{hour mod } 12) \ \times 30°$。

在分钟指针大于 0 的情况下，必须考虑到时针指针额外的移动：它不在整数值之间跳跃，是跟着分针移动。

$$
\text{hour_angle} = \left(\text{hour mod } 12 + \text{minutes} / 60 \right)\times 30°
$$

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMTM0NC9taW51dGVzX2NvcnIyLnBuZw?x-oss-process=image/format,png)
**算法：**
- 初始化常数：`one_min_angle = 6`，`one_hour_angle = 30`。
- 分针指针与 0 点垂线的角度为：`minutes_angle = one_min_angle * minutes`。
- 时针指针与 0 点垂线的角度为：`hour_angle = (hour % 12 + minutes / 60) * one_hour_angle`。
- 得到差：`diff = abs(hour_angle - minutes_angle)`。
- 返回最小的角度：`min(diff, 360 - diff)`。

```python [solution1-Python]
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        one_min_angle = 6
        one_hour_angle = 30
        
        minutes_angle = one_min_angle * minutes
        hour_angle = (hour % 12 + minutes / 60) * one_hour_angle
        
        diff = abs(hour_angle - minutes_angle)
        return min(diff, 360 - diff)
```

```java [solution1-Java]
class Solution {
  public double angleClock(int hour, int minutes) {
    int oneMinAngle = 6;
    int oneHourAngle = 30;

    double minutesAngle = oneMinAngle * minutes;
    double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;

    double diff = Math.abs(hourAngle - minutesAngle);
    return Math.min(diff, 360 - diff);
  }
}
```

```c++ [solution1-C++]
class Solution {
  public:
  double angleClock(int hour, int minutes) {
    int oneMinAngle = 6;
    int oneHourAngle = 30;

    double minutesAngle = oneMinAngle * minutes;
    double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;

    double diff = abs(hourAngle - minutesAngle);
    return min(diff, 360 - diff);
  }
};
```

```go [solution1-Go]
func angleClock(hour int, minutes int) float64 {
    var oneMinAngle, oneHourAngle, minutesAngle, hourAngle, diff float64;
    oneMinAngle = 6;
    oneHourAngle = 30;

    minutesAngle = oneMinAngle * float64(minutes);
    hourAngle = (float64(hour % 12) + float64(minutes) / 60.0) * oneHourAngle;

    diff = math.Abs(hourAngle - minutesAngle);
    return math.Min(diff, 360 - diff);
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$。
* 空间复杂度：$\mathcal{O}(1)$。