### 解题思路
找到一个解题思路近似的，但由于我水平不够，写出来的代码本地运行没问题，在平台上运行显示超时，在此附上我的代码，日后再来修改。
char *convert(char * s, int numRows){
	int i,j=0,len=strlen(s),c=0;
	char *ret;
    char m[numRows][10];
	ret=malloc(sizeof(char)*len);
    while(c<len){
        if(i==0){
            for(i=0;i<numRows&&c<len;i++){
                  m[i][j]=s[c];
                  c++;
           }
           j++;
        }
        if(i==numRows){
            for(i=numRows-2;i>0&&c<len;i--){
                m[i][j]=s[c];
                c++;
            }
            j++;
        }
    }
    int a=0;
    for(j=0;j<numRows;j++)
    	for(i=0;i<10;i++){
    		if(m[j][i]>=65&&m[j][i]<=90&&a<len){
    			ret[a]=m[j][i];
    			a++;
			}	
    	}
    	ret[len]='\0';
		return ret;
}
### 代码

```c
char *convert(char *s, int numRows)
{
    int len = strlen(s);
    /* 针对极端情况 */
    if(numRows > len) {
        return s;
    }
    if(numRows == 1) {
        return s;
    }
    
    int row = 0; /* 二维数组行数 */
    int col = 0; /* 二维数组列数 */
    int index = 0; /* 输入数组索引 */
    
    char arr[1001][1001] = {0}; /* 存放元素的二维数组 */
    char* arr1 = (char*)malloc(sizeof(char)*1001); /* 返回的一维数组 */
    memset(arr1,0,1001); /* 对数组初始化 */
    
    /* 通过二维数组实现按列存储s[index]，通过边界值row < numRows，以及row来转换方向 */
    while(s[index]) {
        while(row < numRows && s[index]) {
            arr[row++][col] = s[index++];
        }
        /* 当row = numRows - 1时 */
        row -= 2;
        col++;
        while(row && s[index]) {
            arr[row--][col++] = s[index++];
        }
    }
    
    /* 二维数组转换为一维数组 */
    int ret = 0;
    for(int i = 0;i < numRows;i++) {
        for(int j = 0;j < col;j++) {
            if(arr[i][j]) { /* 只存储有数值的数字，空字符跳过 */
                arr1[ret++] = arr[i][j];
            }
        }
    }
    
    return arr1;
    
}

// 作者：fuchao
// 链接：https://leetcode-cn.com/problems/zigzag-conversion/solution/cyu-yan-li-yong-er-wei-shu-zu-lai-zhuan-bian-fang-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```