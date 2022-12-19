// 算法：双指针+int和string的转换
// 1.指针i遍历数组，指针k指向压缩后的数组，count计算每个字符的出现次数；新数组原地覆盖，满足进阶的O(1)空间要求
// 2.每遇到1个新字符，将其保存在chars[k]中,count=1,k前进一步,i前进一步；
// 3.如果当前值chars[i] == chars[k]，计数count++，i前进一步；
// 4.如果当前值chars[i] != chars[k]，表示遇到新元素：
// (1)如果count=1，表示上一个元素只出现1次，那就不需要在新数组注明出现次数；
// (2)如果count>1，表示上一个元素重复出现，将count转换为char类型，保存在chars[k]中，k前进相应步数；
// 将新元素chars[i]也保存在chars[k]中，count=1，k和i都前进1步；
// 5.直到遇到数组末尾；
// 6.遍历完数组后，如果数组末尾是几个连续的相同元素，那么需要对最后一个元素的count进行处理，将大于1的count放在数组末尾
// 7.最后一个元素是否重复出现可以根据count判断，count>1表示重复出现
// 8.chars是字符数组，字符的ASCII值在[35, 126]区间内，不包含结束字符'\0'；
// 9.返回新数组长度k。
 
// 特殊情况：只有1个字符，直接返回。


```
#define MAX_LEN 1000

int compress(char* chars, int charsSize)
{
    if (charsSize == 1) {
        return charsSize;
    }

    int i;
    int k = 0; 
    int count = 1;

    for (i = 1; i < charsSize; i++) {
    	// 如果是相同元素，计数器加1
    	if (chars[i] == chars[k]) {
    		count++;
    	} else {	// 遇到新元素
    		if (count > 1) {

    			// 将count转换为字符串
    			// arr中的数字是按大端序保存
    			char arr[MAX_LEN] = {0};	// '\0'
    			int j = 0;
    			while (count) {
    				arr[j]= count % 10  + 48;	// '0'的ASCII码为48，'9'的SCII码为57
    				count = count / 10;
    				j++;
    			}	// 跳出while时，count=0，j表示字符个数
    			// 从arr末尾开始往前，将元素添加到chars中	
    			for (int t = 0; t < j; t++) {
    				k++;
    				chars[k] = arr[j - t - 1];
    			}
    			count = 1;
    		} 

    		// 把新元素加到数组
    		k++;
    		chars[k] = chars[i];  	
    	}
    }

    // 如果数组末尾是几个连续的相同元素，那么需要对最后一个元素的count进行处理，将大于1的count放在数组末尾
    if (count > 1) {
		char arr[MAX_LEN] = {0};	// '\0'
		int j = 0;
		while (count) {
			arr[j]= count % 10  + 48;	// '0'的ASCII码为48，'9'的SCII码为57
			count = count / 10;
			j++;
		}	// 跳出while时，count=0，j表示字符个数
		// 从arr末尾开始往前，将元素添加到chars中	
		for (int t = 0; t < j; t++) {
			k++;
			chars[k] = arr[j - t - 1];
		}
    }

    return k + 1;
}
```
