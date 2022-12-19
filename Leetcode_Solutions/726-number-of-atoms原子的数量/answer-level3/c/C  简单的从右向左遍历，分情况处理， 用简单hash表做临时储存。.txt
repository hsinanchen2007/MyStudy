```
#include<ctype.h>
char * countOfAtoms(char * formula){
	
	int store[26][27] = {0};  //可能没有第二个字母，用第0位表示一位元素 (H、O)
	
	int stack[50]; //系数栈，为了应对多重括号的情况，此时满足先进后出，后进先出。
	int top = 0;
	
	int numTemp = 0; //数不止一位，用numTemp表示暂存的数。

	int coefficient = 1; //此时元素应该乘以的系数。
	int length = strlen(formula);
	
	for(int i = length - 1; i >= 0;) // 从右往左遍历
	{
		if(isdigit(formula[i])) //数字（如果有的话）一定出现最右边，所以最先考虑数字。
		{
            int digit = 1;
			numTemp +=  (formula[i] - '0') * digit;
			while(isdigit(formula[--i])) // 数字不止一位，所以需要做转换。先出现的数是低位，
			{
                digit *= 10;
				numTemp +=  (formula[i] - '0') * digit;
			} // 这里连续--i，没有做越界判断，因为题目所给的是合法化学式，数字不可能在最左边。
			coefficient *= numTemp; //改变系数。
			stack[top++] = numTemp; //将数字push进栈。
            //只要出现了数字，就做相同的处理，不考虑数字是在元素之后，还是括号之后
            //所以pop的时机也是在出现左括号和发现元素之后。
		}
		
		if(formula[i] == ')')
		{
			
			numTemp = 0;
            //将出现的数字断开。
		}
		
		if(formula[i] == '(')
		{
			coefficient /= stack[--top];
            //将最近乘入的系数的数字pop出栈。并且回退系数。
            //数字不可能出现在左括号的右边，所以不需要断开数字
            
		}
		
        if(isupper(formula[i])) //循环变量的递减方式决定了必须先考虑大写字母。如果交换顺序会报错。
		{
			store[formula[i] - 'A'][0] += 1 * coefficient;
			if(numTemp != 0) //元素右边不一定是数字，只有右边是数字时才需要对系数进行操作。
			{
				coefficient /= stack[--top];
				numTemp = 0;
			}
		}

		if(islower(formula[i])) //遇到小写字母时，前面必然是大写字母，所以直接使用formula[i - 1]
		{
			store[formula[i - 1] - 'A'][formula[i] - 'a' + 1] += 1 * coefficient;
	
			if(numTemp != 0)
			{
				coefficient /= stack[--top];
				numTemp = 0;
			}
			i--; //走了两步。
		}
	
        i--;
	}

	char* ret = (char*)malloc(1000 * sizeof(char));
	int tail = 0;

	for(int i = 0; i < 26; i++)
	{
        if(store[i][0] == 1) 
        {
            tail += sprintf(ret + tail,"%c", i + 'A');
        }
        else if(store[i][0] > 1)
		{
			tail += sprintf(ret + tail,"%c%d", i + 'A', store[i][0]);
		}
		for(int j = 1; j <= 26; j++)
        {
            if(store[i][j] == 1)
            {
                tail += sprintf(ret + tail,"%c%c", i + 'A',j - 1 + 'a');
            }
            else if(store[i][j] > 1)
		    {
			    tail += sprintf(ret + tail,"%c%c%d", i + 'A',j - 1 + 'a', store[i][j]);
		    }
           
        }
	}
			       
	return ret;
}
```
