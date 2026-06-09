auto a_temp= a;
	cout << "a: " << endl;

	char charr;
	for (int i = 0; i < int(a.size()/2); i++)
	{
		charr = a[i];
		a[i] = a[a.size()-1-i];
		a[a.size() - 1 - i] = charr;
	}