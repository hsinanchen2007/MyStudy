class Solution {
public:
    string Vowel = "aeiouAEIOU";
    bool findVowel(char a)
{
	string::size_type positionA;
	positionA = Vowel.find(a);
	if ((positionA != Vowel.npos))
	{
		return 0;
	}
	else
		return 1;
}
    string reverseVowels(string s) {
        
	int i = 0,j = s.size() - 1;
	char s_temp;
	for (; i < j;)
	{
		while (findVowel(s[i])&&(i<j))
		{
			i++;
		}
		while (findVowel(s[j]) && (i<j))
		{
			j--;
		}
		
		s_temp = s[i];
		s[i] = s[j];
		s[j] = s_temp;
		i++;
		j--;
	}
    return s;
    }
};