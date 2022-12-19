
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了62.48%的用户


int fib(int N) {
	if (N == 0) return 0; //0的话直接返回0
	queue<int> v;
	v.push(0);
	v.push(1);
	int temp = 0;;
	for (int i = 1; i < N; ++i)
	{
		temp = v.front(); //取出队尾
		v.pop();//删掉第一个元素
		v.push(temp + v.front());//相加，然后送入队，这样队中永远只有两个元素了
	} 
	return v.back();//直接返回队尾元素即可

}
