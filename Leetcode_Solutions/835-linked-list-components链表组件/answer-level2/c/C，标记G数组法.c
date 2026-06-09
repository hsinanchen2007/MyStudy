这题上个月初次看了以后，感觉很难，一度放弃了。
昨天再次分析思考一下，发现没有想象中那么恐怖。
![1.png](https://pic.leetcode-cn.com/c6cbb94b6c9e6e9ce011dc137db459547f6310b5b8c6dd1a728add888fc303af-1.png)

1、创建a字符串，并且全为0（也可以用int数组，但是这个耗空间）；
2、将G中出现过的元素，将其数值对应的a下标改为1；
3、遍历head，如果链表元素在G中出现，则开始计数，并且flag=1;如果不出现，则flag=0。



```
	int  count = 0, flag = 0;
    char *a = (char*)calloc(10000, sizeof(char));
	for (int i = 0; i < GSize; i++){
		a[G[i]] = 1;
	}
	while (head){
		if (a[head->val]){
            if(flag==0)
            count++;
			flag = 1;
		}
		else
			flag = 0;			
		head = head->next;
	}
    free(a);
	return count;
```
