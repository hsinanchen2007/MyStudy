### 解题思路
1.判断传进来的值是否溢出，然后判断x的正负，将符号保存下来，无论正负统一按正数处理先，创建队列；2.将x各个位上的数字逆序入队，然后用i记录位数，j记录个数；3.判断j是否大于1，大于必定溢出（其实没必要，我想多了，传进来的数字位数不可能大于11），然后进入循环逆序出队，并在中间判断是否逆序后的值是否溢出；4.判断符号变量的大小，然后返回值。ps:用队列实现可谓又复杂又冗余，我也不知道为啥第一选择就是使用队列去实现==

### 代码

```cpp
#include<queue>
class Solution {
public:
    int reverse(int x) {
		 queue<int> a;
   if(x>=2147483647||x<=-2147483648)return 0;
   int fuhao=1;
   if(x/(-1)>0){
   	cout<<"传进负数"<<endl; 
    fuhao=-1;
   	x=x/(-1);
   }
   int i=1,j=0;
   int tmp;
   while(x/10!=0){
   	tmp=x%10; 
   	x=x/10;
  // 	cout<<"tmp:"<<tmp<<","<<"x:"<<x<<endl;
   	a.push(tmp);
	   i=i*10;
	   j++;  	
   }
   a.push(x);
   j++;
   if(j>=11)return 0;
   long int t1=0,t2=0;//1用来接受结果，2用来保存队列出来的数 
   while(!a.empty()){
   	t2=a.front();
   	t1=t1+t2*i;
   	if(t1>2147483647)return 0;
   	i=i/10;
   	cout<<"t1:"<<t1<<","<<"t2:"<<t2<<","<<"i:"<<i<<endl;
   	a.pop();
   }
   if(fuhao==1)
    return t1;
    else return t1*(-1);
}

};
```