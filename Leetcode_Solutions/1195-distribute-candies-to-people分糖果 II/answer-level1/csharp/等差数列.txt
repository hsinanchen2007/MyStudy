解题思路: 在草稿纸上手动排列一下观察得出两个等差数列，一个公差为1，一个公差为 num_people(小朋友个数).
只需要等等差数列求和，同时判断是否分配的数列超过了总数即可。时间复杂度 O(n) n为小朋友人数。不过不知道为什么，别人家的代码用等差数列能击败90%以上的用户而我的只能击败28%。 难道是语言问题？
代码如下：
```
public int[] DistributeCandies(int candies, int num_people) {
			var peoples = new int[num_people];
			var suppose = (-1 + Math.Sqrt((1 + 4 * 2 * (long)candies))) / 2;
			var round = (int)((suppose - (suppose % num_people)) / num_people) + 1;
			for ( var index = 1; index <= num_people; index++ ) {
				var peopleIndex = round * num_people - (num_people - index);
				var predistributed = (round - 1) * num_people + index;
				var distributed = peopleIndex * 1 + ((peopleIndex * (peopleIndex - 1)) / 2) * 1;
				if ( candies >= distributed ) {
					peoples[index - 1] = round * index + ((round * (round - 1)) / 2) * num_people;
				} else {
					var lastRound = round - 1;
					var last = (peopleIndex - 1) * 1 + (((peopleIndex - 1) * ((peopleIndex - 1) - 1)) / 2) * 1;
					var surplus = candies - last;
					if ( surplus > 0 ) {
						peoples[index - 1] = lastRound * index + ((lastRound * (lastRound - 1)) / 2) * num_people + surplus;
					} else {
						peoples[index - 1] = lastRound * index + ((lastRound * (lastRound - 1)) / 2) * num_people;
					}
				}

			}
			return peoples;
		}
```
