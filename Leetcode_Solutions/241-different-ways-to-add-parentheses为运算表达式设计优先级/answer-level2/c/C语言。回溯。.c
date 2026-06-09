```
/**
 * 遍历字符串，遇到符号就将符号两边的字符串递归，然后通过符号计算两个递归返回的结果集，存在结果中返回给上一层。
 * 递归结束条件是字符串中没有符号，直接返回。
 */

#define compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, symbol) \
{ \
    leftSize = 0; \
    rightSize = 0; \
    leftNums = NULL; \
    rightNums = NULL; \
    leftNums = _diffWaysToCompute(input, start, i - 1, &leftSize); \
    rightNums = _diffWaysToCompute(input, i + 1, end, &rightSize); \
    for(l = 0; l < leftSize; l++){ \
	for(r = 0; r < rightSize; r++){ \
            returnNums[(*returnSize)++] = leftNums[l] symbol rightNums[r]; \
	} \
    } \
    free(leftNums); \
    free(rightNums); \
}

int* _diffWaysToCompute(char* input, int start, int end, int* returnSize){
    int i, leftSize, rightSize, l, r;
    int *leftNums, *rightNums;
    int *returnNums = (int*)malloc(sizeof(int) * 4096);
    bool isNumber = true;
    for(i = start; i <= end; i++){
        if(!(input[i] >= '0' && input[i] <= '9')){		
            isNumber = false;		
	    switch(input[i]){
	        case'+':
		    compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, +);
	            break;
		case '-': 
		    compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, -);
		    break;
         	case '*': 
		    compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, *);
		    break;
		case '/': 
		    compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, /);
		    break;
		default: 
		    break;
	    }
	}
    }
	 
    if(isNumber){
        char* buf = (char*)malloc(sizeof(char) * (end - start + 2));
	for(i = 0; start + i <= end; i++){
	    buf[i] = input[start + i]; 
	}
	buf[i] = '\0';
	returnNums[(*returnSize)++] = atoi(buf);
	free(buf);
    }
	
    return returnNums;
}
int* diffWaysToCompute(char * input, int* returnSize){
    *returnSize = 0;
    int *returnNums = (int*)malloc(sizeof(int) * 1024);
	
    returnNums = _diffWaysToCompute(input, 0, strlen(input) - 1, returnSize);

    return returnNums;
	
}
```
