### 解题思路
//思路：用栈即可
实现Stackpp函数: 当前指针p解引用若是#并且当前栈内有字母 就让字母出栈  否则该字母入栈 遍历完成返回该栈的长度
最终判断两个栈是否相等即可  

### 代码

```c
int Stackpp(char* p,char *Stack){
	int i = -1;//-1表示空栈
	while (*p){
		if (*p >= 'a'&&*p <= 'z'){  //入栈
			Stack[++i] = *p;
		}
		else if (*p == '#'){  //遇见退格
			if (i != -1){ //当前栈不为空 出栈
				i--; 
			}
		}
		p++;
	}
	return i;
}
bool backspaceCompare(char * S, char * T){
	char *StackS = (char*)malloc(sizeof(char)* 201);
	char *StackT = (char*)malloc(sizeof(char)* 201);
	int i = 0, j = 0;
	i = Stackpp(S, StackS);
	j = Stackpp(T, StackT);
	if (i != j){   //两栈长度不一样必定为false
		return false;
	}
	else{
		for (i = 0; i <= j; i++){   //否则比较两个栈
			if (StackS[i] != StackT[i]){
				return false;
			}
		}
	}
	return true;
}
```