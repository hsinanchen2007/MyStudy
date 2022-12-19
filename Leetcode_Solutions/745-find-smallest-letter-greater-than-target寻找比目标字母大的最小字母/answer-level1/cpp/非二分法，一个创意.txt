判断比target大的字符是否存在于vector内，耗时16ms
`
        while (1)
		{
			target += 1;
			target = ((target - 'a') % 26) + 'a';
			if (std::find(letters.begin(), letters.end(), target) != letters.end())
				return target;
		}
`