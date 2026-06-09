![微信图片_20200329183037.png](https://pic.leetcode-cn.com/69cd32f11ca987369c50b4847a44a68eb3c6a5ea522cbb3ec4d4c0a374e01c00-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200329183037.png)





int strStr(char * haystack, char * needle){
    if(needle[0]=='\0')
    {
        return 0;
    }
   	int p_len = (int)strlen(needle);
	int t_len = (int)strlen(haystack);
	int* n;
	n = (int*)malloc(sizeof(int) * p_len);
	CalcNext(needle, n);
	int i = 0;
	int j = 0;
	int ans = -1;
	while (i < t_len)
	{
		if (j == -1 || haystack[i] ==needle[j])
		{
			++i;
			++j;
		}
		else
		{
			j = n[j];
		}
		if (j == p_len)
		{
			ans = i - p_len;
			break;
		}
	}
	return ans;
}
void CalcNext(char* p, int next[])
{
	int nLen = (int)strlen(p);
	next[0] = -1;
	int k = -1; //k表示next[j-1];
	int j = 0;
	while (j < nLen - 1)
	{
		if (k == -1 || p[j] == p[k]) //如果相等
		{
			++k;
			++j;
			next[j] = k;//next[j+1]=k+1;
		}
		//不相等，去找next[k]
		else
		{
			k = next[k];
		}
	}
}
