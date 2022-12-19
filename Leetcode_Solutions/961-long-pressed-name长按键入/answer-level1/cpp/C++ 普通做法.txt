具体思路写在注释里了
![image.png](https://pic.leetcode-cn.com/e52a9417589906dbd7a5715efe598938b2fcef8bc7625ab2433b4c23e5ab3b95-image.png)

```
    int x = name.size(),y=0;
	for (int i = 0; i < x; i++){       //i标识指向name的元素，y指向typed的元素
		while (name[i] == name[i + 1]){    //name中出现连续同样字符，i与y都向后推
			i++;
			y++;
		}
		int z = y;     //后面用来比较是否遍历过（是否有相同元素）
		while (typed[y] == name[i]){  //长按则y后推
			y++;
		}
		if (z == y){      //若是无后推过则表示出现不同元素，直接返回false
			return false;
		}
	}
	return true;
```
