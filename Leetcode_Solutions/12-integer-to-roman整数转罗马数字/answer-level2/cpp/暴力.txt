class Solution {
public:
	string trans(int a)
	{
		switch (a)
		{
		case 1000:return "M";
		case 900:return "CM";
		case 500:return "D";
		case 400:return "CD";
        case 100:return"C";
		case 90:return "XC";
		case 50:return "L";
		case 40: return "XL";
		case 10:return"X";
		case 9:return "IX";
		case 5:return "V";
		case 4:return "IV";
		case 1:return "I";
            default:return "OO";
		}
	}
	string intToRoman(int num) {
		string s;
		int a[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 }, i = 0;
		while (num)
		{
			while (num >= a[i])
            {
                s.append(trans(a[i]));
                num -= a[i];
            }	
			i++;
		}
		return s;
	}
};