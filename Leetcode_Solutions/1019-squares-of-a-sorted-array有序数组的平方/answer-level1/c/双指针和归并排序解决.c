### 解题思路
1.先遍历负数部分并将其平方  负数平方后为降序 P1记录当前最后一个负数位置 
2.然后以相同的方法遍历正数部分 正数部分为升序 P2记录正数部分的第一个位置 
3.再使用归并排序p1向前遍历  p2向后遍历 时间复杂度 O(2n) 

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
	int *ret = (int*)malloc(ASize*sizeof(int));
	int* p1 = A, *p2 = NULL;
	int i = 0;
	while (p1 < A + ASize){//负数部分
		if (*p1 < 0){
			*p1 *= *p1;
			p1++;
		}
		else{
			p2 = p1;
			break;
		}
	}
    p1 = p1 - 1;
	while (p2&&p2 < A + ASize){//若p2为空则说明没有正数 防止访问空指针
		*p2 *= *p2;
		p2++;
	}
	p2 = p1 + 1;
	//归并排序
	while (p1 >= A&&p2 < A + ASize){
		if (*p1 < *p2){
			ret[i++] = *p1;
			p1--;
		}
		else{
			ret[i++] = *p2;
			p2++;
		}
	}
	//剩下的直接放进结果数组即可
	while (p1 >= A){
		ret[i++] = *p1;
		p1--;
	}
	while (p2&&p2 < A + ASize){
		ret[i++] = *p2;
		p2++;
	}
	*returnSize = ASize;
	return ret;
}

```