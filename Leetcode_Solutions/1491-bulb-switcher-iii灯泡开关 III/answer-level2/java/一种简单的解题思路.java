```
解题思路：每一次点量任意一个位置的灯,判断它前面一个和后面一个灯的状态
		1.如果它前面的灯亮着，那么当前位置灯就应该变成蓝色的;
		2.如果它后面的灯亮着，那么后面的灯也应该变成蓝色的;
		3.0号位置实际是不存在灯泡的，但采用这种思路，它对第一号位置的灯的状态有影响，所以0号位置默认设置为亮着
具体实现看代码注释;
```

```
public static int numTimesAllBlue(int[] light) {
		//count用来记录当前亮着的灯都为蓝色的次数
		int count = 0;
		//记录当前亮着的灯
		int curr_light = 0;
		//记录当前为蓝色的灯
		int curr_blue = 0;
		//0,灯没亮;1,灯亮;2,灯为蓝色;因为n的最大值为50000所以,这里数组的长度为50010
		int[] state_light = new int[50010];
		//0号位置不存在灯,但是会对1号位置产生影响,所以设置为1
		state_light[0]=1;
		for (int i : light) {
			//点亮第i位置的灯,当前亮着的灯数量加一
			state_light[i] = 1;
			curr_light++;
			//如果当前位置的后一个灯是亮着的,那么后一个位置的灯应该变成蓝色的
			if (i<(state_light.length-1)&&state_light[i+1]==1) {
				state_light[i+1] = 2;
				curr_blue++;
			}
			//如果当前位置的前一个灯也是亮着的,那么当前位置的灯也应该变成蓝色的
			if (i<state_light.length&&(i-1)>=0&&state_light[i-1]>=1) {
				state_light[i] = 2;
				curr_blue++;
			}
			//如果当前亮着的灯的数目与蓝色灯的数目相等,count加一
			if (curr_blue==curr_light) {
				count++;
			}
		}
		return count;
    }
```
