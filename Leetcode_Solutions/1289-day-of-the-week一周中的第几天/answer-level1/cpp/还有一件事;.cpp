难点就是计算天数；从1971年1月1日到当前日期的天数计算。
在计算天数的过程中，可能碰到平年或闰年，分开对待就可以了。
特别要注意两点：
1.当前年的天数，需要根据  month 和 day 的值来计算；
2.若输入是1971年1月1日，本算法中sumday求出应该等于1，  x = sumday%7， x = 1，
已知string days[7] = { "Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };
若函数返回值 取days[x] 就不对了；
故计算当前一天的日子，用
x = (sumday - 1)%7;
返回 days[x];



class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
		int monthss[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };  
        //定义的时候需要初始化；
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			monthss[1] = 29;
		}
		int Sumdays = 0;
		string days[7] = { "Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };

		//计算年数（平年 润年）；
		int sumleap = 0;
		int notleap = 0;
		
		
		for (int i = 1971; i < year; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			{
				sumleap++;
			}
		}
		if (monthss[1] == 29)
		{
			//当前年为闰年；
			sumleap++;
			notleap = year - 1971 - sumleap + 1;   //加一因为1971年是平年；
			Sumdays = notleap * 365 + (sumleap - 1) * 366;//不能算当前年；
		}
		else
		{
			//当前年为平年；
			notleap = year - 1971 - sumleap + 1 - 1;   //加一因为1971年是平年；减一是因为当前年需要几月，几日来计算；
			Sumdays = notleap * 365 + sumleap * 366;//不能算当前年；
		}

		//再计算月份的天数；存入总天数中；（如果month == 3 就只加1，2月的满天数， 3月的天数放在 day 中；）
		for (int i = 0; i < month - 1; i++)
		{
			Sumdays += monthss[i];
		}

		//因此，总天数就为：
		Sumdays += day;
		//然后除以7取余；
		int remainder = (Sumday - 1)s%7;
        return days[remainder];

    }
};
