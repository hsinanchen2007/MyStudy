用一个pos定位空格位置

用left,right 指针处理单个单词返转   直到结束 

string reverseWords(string s) {
	string res = "";
	int slen = s.length();
	if (0 == slen) {return res;}
    if(1 == slen|| 2 == slen) {  return s;}

	int left = 0; //处理单个单词左指针
	int right = 0; //处理单个单词右指针
	int pos = 0; //保存空格的位置
	while (pos < slen)
	{
		while ((pos < slen) && s[pos] != ' ')pos++; //处理一个单词
		right = pos - 1;
		while (left < right)
		{
			swap(s[left++], s[right--]);
		}
		left = pos + 1;
		pos++;  //将指针移到下一个单词头   
	}
    return s;
   }