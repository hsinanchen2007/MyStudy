### 解题思路
思路： 由题意 分析得出 当股价为 低-高-低 这种情况进行买进和卖出的操作 利润是为最终的利润是最可观的 
首先top指针指向数组第一个元素 用tail指针从第二个往后找有以下情况：
1.*top>*tail  此时top = tail  tail++ 直到top和tail满足*top<*tail 即低-高的情况
2.*top<*tail  此时满足低-高的情况  tail往后遍历 直到*tail>*(tail+1) 即满足低-高-低这种情况 此时进行一次买进和卖出的操作 然后top = tail+1
tail++; 重复以上操作即可

（防止指针的越界等细节需要注意 代码里有体现） 

### 代码

```c
int maxProfit(int* prices, int pricesSize){
	int ret = 0;
	if (pricesSize < 2){
		return ret;
	}
	int *top = prices, *tail = top+1;
	while (tail <= prices + pricesSize - 1){
		if (*tail < *top){
			top = tail;
			tail++;
		}
		else if (*top<*tail){
			if (tail == prices + pricesSize - 1){
				ret += *tail - *top;
				return ret;
			}
			else if (*tail>*(tail + 1)){
				ret += *tail - *top;
				top = tail + 1;
				tail = top + 1;
			}
			else{
				tail++;
			}
		}
		else{
			tail++;
		}
	}
	return ret;
}
```