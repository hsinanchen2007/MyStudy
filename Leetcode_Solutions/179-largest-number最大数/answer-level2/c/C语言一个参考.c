执行用时 :12 ms, 在所有C提交中击败了91.18%的用户
内存消耗 :7.1 MB, 在所有C提交中击败了83.33%的用户
解决这个问题：
1，最关键的是自己定义一个比较函数，这个函数的功能是比较S1与S2,是S1S2
 大还是S2S1大，在两个数都不为0的时候分别求出位数互相乘比较即可。但是在S2==0的时候
（即插入排序的key为0），则不需要进行交换操作，这种情况需要单独列出来
2，确定好比较函数之后就是插入排序了，设置一个key，每次比较插入，这里就不多说了。
此处有一个需要注意的点，在comp函数中可以置一个指针型变量，用来对key的位数的计数，
因为最后的输出是一个指针字符串，需要申请地址，此时你可以按照最多情况，即numsSize*10
,nums中每个数字都是满位，但是肯定是有空间浪费，使用指针型变量记录每一个key，则
可以做到空间不浪费，但是不知道为啥我没有成功。可以作为后续改进点。
3，最后就是数组转字符数组，此时，要判定，若nums[0]==0，则nums内均为0，只需要输出一个
0即可。则建立输出字符串，对nums内每一个字符串用sprintf进行变化然后拼接到S中，最
后输出S即可。
``` 
int comp(int *nums,int a,int key);
char * largestNumber(int* nums, int numsSize) {
	/* 排序函数 */
	if(numsSize>=2) { //numsSize<=1的时候不需要排序，直接进行字符串转换输出即可。
		int i,j,key,flag;
		for(i=1; i<numsSize; i++) {
			key=nums[i];
			j=i-1;
			while(j>=0&&(comp(nums,j,key)==0)) {
				nums[j+1]=nums[j];
				j--;
			}
			nums[j+1]=key;
		}
	}
	/* 转字符串输出函数 */
	char *s=(char*)calloc(numsSize*10,sizeof(char));
	if(nums[0]==0) sprintf(s,"%d",nums[0]);
	else{
		for(int i=0; i<numsSize; i++) {
			char *s1=(char*)calloc(11,sizeof(char));
			sprintf(s1,"%d",nums[i]);
			strcat(s,s1);
		}
	}
	return s;
}
int comp(int *nums,int a,int b) {
	if(b==0) return 1;
	int tmp1=nums[a],tmp2=b,counta=0,countb=0;
	int flag;
	while(tmp1!=0) {
		counta++;
		tmp1/=10;
	}
	while(tmp2!=0) {
		countb++;
		tmp2/=10;
	}
	if((nums[a]*pow(10,countb)+b)>(b*pow(10,counta)+nums[a])) flag=1;//自定义排序 a>=b
	else flag= 0;//自定义排序 a<b
	return flag;
}
```