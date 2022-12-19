### 解题思路
- 暴力破解清爽直白但是低效；
- 规律公式难找，但极其高效；
- 难得自己捣鼓出高效的算法，写代码只是个验证过程，思为先再写也不迟，磨刀不误砍柴工是有道理的；

### 代码

```java
class Solution {
	/**
	 * @author: ZhouJie
	 * @date: 2020年3月5日 下午6:56:18 
	 * @param: @param candies
	 * @param: @param num_people
	 * @param: @return
	 * @return: int[]
	 * @Description: 2-确定规律，然后再分配，先找完整分配的轮数，然后确定基数和增量，一次遍历分配中顺带分配最后剩余不完整的一轮即可；
	 *
	 */
    public int[] distributeCandies(int candies, int num_people) {
		int[] rst = new int[num_people];
		// 倒数第二次分出去的是n个糖果，则n*(+1)/2<=candies；
		// 一元二次方程的根公式，若a*x²+b*x+c=0，则 x=(-b±sqrt(b*b-4ac)/2a)；
		int n = (int) ((Math.sqrt(2 * candies + 0.25) - 0.5));
		// time是总共完整分配的轮次数
		int time = n / num_people;
		// time次分配完成时，第一个人分配到base个，后续每个人总比前一个人多分配time个；
		// 第一个人每次分到的数量：1、1+num_people、1+2*num_people、1+3*num_people...1+(time-1)*num_people
		// 故第一个人分到：rst[0]=time+num_people*(time*(time-1)/2)
		int base = (int) (time + num_people * time * (time - 1) * 0.5);
		// time次分配完成后，处理remaining和lastTime的分配
		// remaining为最后一次分出去的糖果数，若为0则说明不存在最后一次不够分配
		// lastTime为最后一轮可够分的人数
		// 若lastTime不为0，则第1到lastTime的人将依次分到(n-lastTime)~n个糖果，第lastTime+1人将分走最后的remaining
		// 若lastTime为0，则第一个人将分走最后的remaining，此时remaining可能为0
		int remaining = (int) (candies - n * (n + 1) * 0.5);
		int lastTime = n % num_people;
		for (int i = 0; i < num_people; i++) {
			rst[i] = base + time * i;
			if (i < lastTime) {
				rst[i] += time * num_people + 1 + i;
			}
		}
		rst[lastTime] += remaining;
		return rst;
    }
}
```