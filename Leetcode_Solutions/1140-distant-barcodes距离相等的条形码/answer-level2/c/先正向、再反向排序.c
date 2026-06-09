
正向逐个匹配，遇到不匹配则找下一个满足匹配的条形码，然后进行交换，直到结束或者找不到满足的条件的条形码。

如果是找不到满足条件的条形码，则反向使用同样的算法执行一遍。


int sort(int* barcodes, int barcodesSize) {
	int i = 0;
	int j;
	int temp;
	int swapindex;
	
	if (barcodesSize <= 2) {
		return 0;
	}
	
	do {
		j = i + 1;
		if ((i >= barcodesSize) || (j >= barcodesSize)) {
			break;
		}
		
		if (barcodes[i] != barcodes[j]) {
			// 条形码不同，满足匹配
			i++;
		} else {
			swapindex = j;
			// 找到下一个不同的条形码，并进行交换
			for (; j < barcodesSize; j++) {
				if (barcodes[swapindex] != barcodes[j]) {
					break;
				}
			}
			// 未找到
			if (j == barcodesSize) {
				return -1;
			}
			
			// swap
			temp = barcodes[swapindex];
			barcodes[swapindex] = barcodes[j];
			barcodes[j] = temp;
			
			i = swapindex;
		}
	} while (1);
	
	return 0;
}

int sort2(int* barcodes, int barcodesSize) {
	int i = barcodesSize - 1;
	int j;
	int temp;
	int swapindex;
	
	if (barcodesSize <= 2) {
		return 0;
	}
	
	do {
		j = i - 1;
		if ((i < 0) || (j < 0)) {
			break;
		}
		
		if (barcodes[i] != barcodes[j]) {
			// 条形码不同，满足匹配
			i--;
		} else {
			swapindex = j;
			// 找到下一个不同的条形码，并进行交换
			for (; j >= 0; j--) {
				if (barcodes[swapindex] != barcodes[j]) {
					break;
				}
			}
			// 未找到
			if (j < 0) {
				return -1;
			}
			
			// swap
			temp = barcodes[swapindex];
			barcodes[swapindex] = barcodes[j];
			barcodes[j] = temp;
			
			i = swapindex;
		}
	} while (1);
	
	return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize){
	int *out;
	int ret;
	
	out = malloc(barcodesSize * sizeof(int));
	memcpy(out, barcodes, barcodesSize * sizeof(int));
	ret = sort(out, barcodesSize);
	if (-1 == ret) {
		sort2(out, barcodesSize);
	}
	*returnSize = barcodesSize;
	return out;
}

