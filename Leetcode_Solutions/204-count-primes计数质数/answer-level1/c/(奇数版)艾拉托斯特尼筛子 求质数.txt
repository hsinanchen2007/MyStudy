### 解题思路
1.在艾拉托斯特尼筛子基础上增加奇数限制（因为除了2，所有的偶数都不可能是质数）；
2.优点：减少空间过度占用，同时降低时间复杂度，第一次通过自己的努力战胜93%！
3.注意：注意方式堆溢出，malloc和free的匹配，防止崩溃。

### 代码

```c
int countPrimes(int n){

    /******(奇数版)艾拉托斯特尼筛子*****/
	int i = 0;
	int j = 0;
	int size = 0;
	int cnt = 0;
	if(n <= 2)
		return 0;

	cnt = 1;
    size = n/2-1;   //求小于M的除1外的奇数个数

	bool* arr = NULL; 

	if((arr=(bool*)malloc(sizeof(bool)*size)) == NULL)	//申请失败，跳出
	{
		//cout<<"HowManyPrime1_2的堆申请失败！"<<endl;
		return -1;
	}

	for(i = 0; i < size; i++)
	{
		arr[i] = true;
	}

	for(i = 0; i <= (size-1); i++)
	{
		if(arr[i] == true)
		{
			cnt++;
			for(j = i+((i+1)*2+1); j < size; j = j+((i+1)*2+1))		//奇数配合跳跃
			{
				arr[j] = false;
			}
		}
	}
	free(arr);
	arr = NULL;	 //释放后应该把指向这块内存的指针指向NULL，防止程序后面不小心使用了它

	return cnt;

}
```