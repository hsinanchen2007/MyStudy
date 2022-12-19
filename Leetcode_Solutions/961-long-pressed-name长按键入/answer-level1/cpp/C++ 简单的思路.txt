	核心思想就是按下标依次比 用一个字符串name2用于存放name和typed的比较情况。
	最后根据name2的更新情况判断返回值。
![11111.PNG](https://pic.leetcode-cn.com/f072a7e5e88390b5a6c2bf4f0e384dda9cb01ec5a91c739d4f6de171cb31067d-11111.PNG)

	bool isLongPressedName(string name, string typed) {
    	if (name == typed)//两个一样返回true
		return true;
	else if (name.length() > typed.length())//n>t返回false 因为检查重复键时 正确长度一定小于错误重复输入的长度
		return false;
	else {
		bool flag = true;
		string name2 = name;//name2为一个判断字符串 name2的各位用于存放name和typed的比较情况，更改了就更新值
		for (int i = 0, j = 0; j < typed.length();) {//逐个检查 i->name j->typed
			if (name[i] == typed[j]) {
				name2[i] = '#';//给name2的第i位赋值
				i++;
				j++;
			}
			else {
				if(name[i-1] == typed[j])//判断typed j位是否多输入
					j++;
				else
					i++;
			}
		}
		for (int i = 0; i < name2.length(); i++)//依次判断name2的各位是否更改
			if (name2[i] != '#') {
				flag = false;
				break;
			}
		return flag;
	}
}