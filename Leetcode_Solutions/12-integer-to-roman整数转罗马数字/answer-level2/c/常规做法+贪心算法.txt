首先将每个罗马数字（以及一些特殊的两位罗马数字）能够表示的数列出来如下所示：
1000, 900, 500, 400,  100,  90,  50,   40,   10,   9,   5,    4,   1
"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
然后通过组合这些数字来凑出我们想要的那个数字。

**常规做法**
（1）关键代码在于while的循环，对每个罗马数字对应的整数取商，能够得到该整数可以包含商个该罗马数字。比如说整数3661，3661/1000=3（整数除法），也就是说前三位都应该是MMM。然后我们通过取余的方式去掉最高位，即得到661。下一步我们对900做除法，然后取余。以此类推，可以得到每个罗马数字所对应的出现的次数（也就是代码中定义的flag数组）。
（2）最后我们通过字符串拼接的方式，结合上一步中得到的每个罗马数字出现的次数来得到最终的答案。
```
#define TYPE_NUM 13
#define RES_LEN 20
char * intToRoman(int num){
	int flag[TYPE_NUM] = {0};
	int type[TYPE_NUM] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char roman[TYPE_NUM][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	char *res = (char *)malloc(RES_LEN * sizeof(char));
	memset(res, 0, RES_LEN);
	int i = 0;
	while(num != 0){
		flag[i] = num / type[i];
		num = num % type[i];
		i++;
	}
	
	for(i = 0; i < TYPE_NUM; i++){
		while(flag[i] > 0){
			strcat(res, roman[i]);
			flag[i]--;
		}
	}
	
	return res;
}
```
**贪心算法**
其实常规方式中感觉也是利用了贪心算法，这里的贪心算法的意思是，给出的这个整数，我最少能用几个这个罗马数字来表示。**也就是说使用尽可能少的罗马符号来表示需要的整数值。**所以代码关键的部分在于while循环。并且值得注意的是while循环的判断语句，只要我这个数大于等于此时对应的最大的罗马数值，那就直接进行字符串的拼接。相比方法1，少了求flag数组的那一步，代码显得更加的简洁，贪心算法的体现也更加明显。
```
char * intToRoman2(int num){
	int type[TYPE_NUM] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char roman[TYPE_NUM][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	char * res = (char *)malloc( RES_LEN * sizeof(char));
	memset(res, 0, RES_LEN);
	int i;
	for(i = 0; i < TYPE_NUM; i++){
		while(num >= type[i]){
			strcat(res, roman[i]);
			num = num - type[i];
		}
	}
	return res;
}
```
