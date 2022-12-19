![014.jpg](https://pic.leetcode-cn.com/6469ebdf0d4f3d5760faa71a3fce63a50bd45749b1b8e21a3512cfd31781ca3a-014.jpg)
```
class Solution {
public:
    int maximumSwap(int num) {
        string tempString;
	bool flag=false;
	int  hign;
	tempString = to_string(num);
	for (int tempInt_0=0;tempInt_0<tempString.size();tempInt_0++)
	{
		char max = tempString[tempInt_0];
		hign = tempInt_0;
		if (!flag)
		{
			for (int tempInt_1 = tempInt_0 + 1; tempInt_1 < tempString.size(); tempInt_1++)
			{
				if (tempString[tempInt_1] >= max&&tempString[tempInt_1]!= tempString[tempInt_0])
				{
					max = tempString[tempInt_1];
					hign = tempInt_1;
					flag = true;
				}
			}
			tempString[hign] = tempString[tempInt_0];
			tempString[tempInt_0]=max;
		}
		else
		{
			break;
		}
	}

	num = 0;
	for (int tempA =0;tempA<tempString.size(); tempA++)
	{
		num = num * 10 + (tempString[tempA] - 48);
	}
    return num;

    }
};

```


