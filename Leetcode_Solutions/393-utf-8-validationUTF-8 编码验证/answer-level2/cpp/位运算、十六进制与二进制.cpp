```
	bool validUtf8(vector<int>& data) {
		int num(0), size(data.size()),i(0);
		int inspect;
		int header;
		while (i < size)
		{
			header = data[i];
			inspect = 0x80;
			num = 0;
			while (header & inspect)
			{
				num++;
				inspect = inspect >> 1;
			}
			if (num == 0)
			{
				i++;
			}
			else if (num>1 && num <= 4 && num <= size && validSubUtf8(data, i+1, i + num)) {
				i += num;
			}
			else return false;
		}
		return true;
	}
	bool validSubUtf8(vector<int>& data, int l, int r) {
		for (int i = l;i < r;i++)
		{
			if ((data[i] & 0xc0) != 0x80)
				return false;
		}
		return true;
	}
```
