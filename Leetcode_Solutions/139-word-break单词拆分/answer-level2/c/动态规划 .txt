执行用时 :4 ms, 在所有 C 提交中击败了89.30%的用户  
内存消耗 :7.1 MB, 在所有 C 提交中击败了47.41%的用户  

### 解题思路
详见代码注释

### 代码

```c
#include <stdlib.h>
#include <string.h>
int wordBreak(char * s, char ** wordDict, int wordDictSize){
//本算法的思路是通过迭代寻找所有可能的单词开始位置处，若找到一个 开始位置 在字符串结尾，说明拆分成功
//初始的开始处在字符串开头，每成功匹配一个单词，则这个单词的结尾的下一个字符位置作为新的单词开始处，若匹配不成功，说明该单词开始处不可行。
    if(wordDictSize==0)
        return 0;
	
	int index[26][wordDictSize+1];//字典首字母索引表
	int pos;
	for(int i=0;i<26;i++)
		index[i][0]=0;
	for(int i=0;i<wordDictSize;i++){
		pos = (int)(wordDict[i][0]-97);
		index[pos][++index[pos][0]]=i;
	}//建立字典的首字母索引表

	int *exchange;
	int *pre=(int *)malloc(sizeof(int)*(strlen(s)+1));
//存放当前的单词开始匹配位置,pre[0]专门用于表示开始位置数目,pre[1]~pre[pre[0]]依次表示开始位置索引
	int *cur=(int *)malloc(sizeof(int)*(strlen(s)+1));
//存放下次的单词开始匹配位置,cur[0]专门用于表示开始位置数目,cur[1]~cur[cur[0]]依次表示开始位置索引

	pre[0]=1;//初始开始匹配位置只有1个，即字符串s开始位置
	pre[1]=0;//开始位置0
	int len;
	
    int isFind[strlen(s)+1];//用于标识位置是否已经被发现过了
    for(int i=1;i<strlen(s)+1;i++)
            isFind[i]=0;//isFind[i]=0表示该开始位置从来没有发现过，isFind[i]=1表示发现过了
    isFind[0]=1; // 表示位置0 已被发现
	
	while(cur[0]!=0){//一旦出现cur[0],则表示再也没有开始位置了并且也没有匹配至字符串结尾
		cur[0]=0;
		for(int i=1;i<=pre[0];i++){//依次遍历每个开始位置,并建立下次的开始位置
			pos = (int)(s[pre[i]]-97);//开始位置的首字母(a~z 用0~25表示)
			for(int j=1;j<=index[pos][0];j++){//依次遍历每个 首字母跟开始位置字母 一样 的单词
				len = strlen(wordDict[index[pos][j]]);
				if(strlen(s)-pre[i]>=len&&strncmp(wordDict[index[pos][j]],s+pre[i],len)==0){//匹配单词成功
					
                    if(isFind[pre[i]+len]==0){//该开始位置未被发现过
                        cur[0]++;
					    cur[cur[0]]=pre[i]+len;
                        isFind[pre[i]+len]=1;
                    }
					if(pre[i]+len==strlen(s)) return 1;//开始位置在字符串s结尾处,表明单词拆分成功
				}//则保存下一个开始位置					
			}
		}
		exchange=cur;
		cur=pre;
		pre=exchange;
	}
	return 0;
}
```