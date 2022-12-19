### 解题思路
这题不能通过判断产生的单词是否在banned内，不然很慢，因此最直接想法就是banned做集合或map
但是有种更好的方法，既然找出现最多，那么直接banned作为-1，任意负数都行，全部放在一个hash表内，通过对比当前与之前那个出现频率大，更新新值。
1.设x为单词个数，假设它单词之间都是空格间隔，那么空格x-1个，不算其他,.?等，x+x-1<=1000，因此单词数最多501个，下面取512，2的幂（便于位运算，此题没冲突，纯巧合？）
2.截取单词：isalphat函数，根据大小写转换返回固定小写，否则其他字符返回0('\0'用于条件终结1)
3.没有必要每次去申请单词字符数组，因为它有可能还不是出现频率最高的，因此使用变量记录起始与终止索引，然后使用maxtime记录出现频率最大即可。

![image.png](https://pic.leetcode-cn.com/7240ad971768b642456c5c2e5f36059d9febd8f6f4024bf7f02937d395b7d21c-image.png)


### 代码

```c
char isalphat(char c){
	if(c>=97&&c<=122) return c;  // 小写
	else if(c>=65&&c<=90) return c + 32;  // 大写变小写
	return 0;  // 非单词 
}

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
	char *tmp,c;  // 暂存字符串
	short i,len=strlen(paragraph),j;
	short table[512]={0},start,end,maxtime=0;
	unsigned long int key = 0;
	
	// 1.处理banned单词进hash表
	for(bannedSize--;bannedSize>=0;bannedSize--){
		for(key=0,i=0;(c=banned[bannedSize][i])!='\0';i++){
			key = (key << 5) - key + c - 97;  // 都是小写
		}
		key = (key&511);  // 得地址
		table[key] = -1;  // 禁用 
	}

	// 2.处理得到单词
	for(i=0;i<len;i++){
		if((i==0||paragraph[i-1]==' ')&&paragraph[i]!=' '){  // 碰到单词
			// j记录i的其实位置 
			for(j=i,key=0;(c=isalphat(paragraph[i]))!=0;i++){
				key = (key << 5) - key + c - 97;
			}
			key = key&511;
			if(table[key]!=-1){
				table[key]++;
				if(table[key]>maxtime){
					maxtime = table[key];
					start = j;
					end = i;  // 多1 
				}
			}

		}
	}

	tmp=(char*)malloc((end-start+1)*sizeof(char));  // 真实长度+1
	for(j=0;start<end;j++,start++) tmp[j] = isalphat(paragraph[start]);
	tmp[j] = '\0';
	return tmp;
}
```