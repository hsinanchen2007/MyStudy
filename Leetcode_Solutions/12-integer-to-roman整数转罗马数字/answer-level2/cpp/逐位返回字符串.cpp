```
class Solution {
private:
	string getC(int pow) {
		switch (pow)
		{
		case 0: return "M";
		case 1: return "C";
		case 2: return "X";
		case 3: return "I";
		default:break;
		}
		return "";
	}
	string transform(int number, int pow) {
		if (number == 0) return "";
		string answer = "";
		if (number == 9 || number == 4) {
			switch (pow)
			{
			case 1: return (number == 9) ? "CM" : "CD";
			case 2: return (number == 9) ? "XC" : "XL";
			case 3: return (number == 9) ? "IX" : "IV";
			default:break;
			}
		}
		else if (number >= 1 && number <= 3) {
			string str = getC(pow);
			for (int i = 0; i < number; ++i) {
				answer.append(str);
			}
		}
		else {
			switch (pow)
			{
			case 1:answer.append("D"); break;
			case 2:answer.append("L"); break;
			case 3:answer.append("V"); break;
			default:break;
			}
			string str = getC(pow);
			for (int i = 5; i < number; ++i) {
				answer.append(str);
			}
		}
		return answer;
	}

public:
	string intToRoman(int num) {
		string answer = "";
		int arr[4];
		for (int i = 0; i < 4; ++i) arr[i] = 0;
		int i = 3;
		while (num > 0)
		{
			int remainder = num % 10;
			arr[i] = remainder;
			--i;
			num /= 10;
		}
		for (int i = 0; i < 4; ++i) {
			answer += transform(arr[i], i);	
		}
		return answer;
	}
};
```
