```
/*
    解题思想：动态规划。
	解题步骤：
		1、确定状态：
			字符串s = “bbbab”
			字符串长度记为：len
			长度为len的字符串中最大回文子序列的长度值记为：M[i,j],其中 i = 0，j = len-1
		2、转移方程：
			a、如果s[i] = s[j]:
				M[i,j] = M[i+1,j-1] + 2,其中 i,j∈[0,len-1]
			b、如果s[i] ≠ s[j]:
				M[i,j] = Max(M[i+1,j],M[i,j-1]);,其中 i,j∈[0,len-1]

		3、初始条件和边界情况：
			a、len = 1：其中(j - i = 0)
				M[i,j] = 1;
			b、len = 2：其中(j - i = 1)
				if(s[i] == s[j]){
					M[i,j] = 2;
				}
				else{
					M[i,j] = 1;
				}
			c、len >= 3：其中(j - i >= 2)
				if(s[i] == s[j]){
					M[i,j] = M[i+1,j-1] + 2;
				}
				else{
					M[i,j] = Max(M[i+1,j],M[i,j-1]);
				}
		4、计算顺序：按照长度从短到长进行计算
			a、第一层循环：字符串长度为变量，len∈[1,len]
			b、第二层循环：(子)字符串的起始索引，j∈[0,len-1]
			
		5、申请一个和最大长度的二维数组存储已计算的过程值，见下图
	注意：
		1、时间复杂度：O(strlen(s)*strlen(s))
		2、空间复杂度：O(1000*1000),因为开辟了一个全局的二维数组去存储过程值。
*/
```


![leetcode.516.最长回文子序列.png](https://pic.leetcode-cn.com/79fc8c0e78d799783a622a1c52140b00bddfb579107eac816c0921608573cabb-leetcode.516.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97.png)


```
#define MAX_SIZE 1000
int record[MAX_SIZE][MAX_SIZE] = {0};//在longestPalindromeSubseq函数体之外申请一个全局二维数组，可以优化内存消耗
int longestPalindromeSubseq(char * s){
    int len;
    int i,j;
    int sublen;
    int sublen1;
    int sublen2; 

    len = strlen(s);
    if(len == 0){
        return 0;
    }
    
    memset(record,0,sizeof(record));  
    
    for(sublen = 1;sublen <= len;sublen++){//第一层循环：子字符串的长度
        for(i = 0;i < len;i++){//第二层循环：子字符串的起始位置
            j = (i + sublen) - 1;
            if(j >= len){
                break;
            }else if(sublen == 1){
                record[i][j] = 1;
            }else{
                if(s[i] == s[j]){
                    record[i][j] = record[i+1][j-1] + 2;
                }else{
                    sublen1 = record[i+1][j];
                    sublen2 = record[i][j-1];
                    record[i][j] = (sublen1 >= sublen2 ? sublen1 : sublen2);
                }
            }
        }
    }
    
    return record[0][len-1];    
}
```
