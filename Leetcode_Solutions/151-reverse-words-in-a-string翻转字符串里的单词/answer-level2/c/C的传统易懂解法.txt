### 解题思路
此处撰写解题思路
![捕获.JPG](https://pic.leetcode-cn.com/c79aee19985f9fd7494df7bcce2247e9710d8202a4c9d00d79c7b9af3ae3e406-%E6%8D%95%E8%8E%B7.JPG)

解题思路为遍历，从后往前遍历s，通过空字符来确定一个单词的首尾index，然后将其传入返回字符串
也可以从前往后，但是在传入返回字符串时要计算返回长度等，较麻烦
### 代码

```c
char * reverseWords(char * s) {
	int len = strlen(s);
	char *res = (char *)malloc(sizeof(char)*(len + 10)); //返回字符串
	memset(res, 0, sizeof(char)*(len + 10));
	int res_len = 0;
    int flag=0;
	for (int i = len - 1; i >= 0; i--) {
		int right=0, left=0; //确定一个单词的首尾index
		if (s[i] != ' ') {
            flag=1;
			right = i;
			for (int j = i; j > 0; j--) {
				if (s[j - 1] == ' ') {
					left = j;
					break;
				}
			}
            if(left<=right){
                for (int t = left; t <= right; t++) {
                    res[res_len++] = s[t];
                }
            }
			res[res_len++] = ' ';
			i = left;
		}
	}
//要注意如果s为空字符串，那么要返回“”，用flag来标记s是否为空字符串
    if(flag==0)
        return "";
	res[res_len-1] = '\0';
//在for循环中在每次输入完一个单词后还要添加一个空格，这里的作用是取消最后一个
//单词后面的空格
    
	return res;
}
```