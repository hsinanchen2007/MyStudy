三次反转：
原始数组                  : 1 2 3 4 5 6 7
反转所有数字后             : 7 6 5 4 3 2 1
反转前 k 个数字后          : 5 6 7 4 3 2 1
反转后 n-k 个数字后        : 5 6 7 1 2 3 4
```c
void reverse(int* nums,int start,int end){
	int temp;
	while(start<end){
		temp=nums[start];
		nums[start++]=nums[end];
		nums[end--]=temp;
	}
}
void rotate(int* nums, int numsSize, int k){
	reverse(nums,0,numsSize-1);
	reverse(nums,0,k%numsSize-1);
	reverse(nums,k%numsSize,numsSize-1);
}
```
环状换座位：
cnt用来计数。若满足numsSize次坐到正确位置，则退出循环。
cur指针指向环的开头。如果环结束走到cur位置cnt却没有满次数的话，cnr指向另一个环的开头。
```c
void rotate(int* nums, int numsSize, int k){
	int cnt=0;
	int temp,pre=nums[0];
	int cur=0,j=0;        
	while(cnt<numsSize){	
		j=(j+k<=numsSize-1?(j+k):((j+k)%numsSize)); //目的地
		temp=nums[j];        //temp存储现在离开座位的元素
		nums[j]=pre;        //pre是上一次离开座位的元素
                            //让上一个元素坐在正确的位置上 
		cnt++;            //每坐到正确的位置cnt+1
		pre=temp; 		  
		if(j==cur && cnt!=numsSize){
			cur++;
			j=cur;
			pre=nums[j];
		}
	}
}
```